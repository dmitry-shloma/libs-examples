/*
  Калькулятор математических выражений (версия 0.5 от 03.12.2007)
  Основан на алгоритме обратной польской нотации

  Вычисляемое выражение не чУвСтВиТеЛЬнО к регистру букв.

  В качестве разделителя целой и дробной части можно использовать
  как точку (.), так и запятую (,)

  В текущей версии поддерживаются следующие функции:
  Sqrt (квадратный корень), Sin, Cos, Tan, CoTan, ArcSin, ArcCos, ArcTan, Exp,
  LogG (десятичный логарифм), LogN (натуральный логорифм)

  Данный калькулятор СЧИТАЕТ ПРАВИЛЬНО в отличии от аналогичных продуктов,
  таких как Numlock калькулятор и т.д, которые НЕ ПРАВИЛЬНО ВЫЧИСЛЯЮТ
  очень длинные и сложные выражения

  Текущая версия не поддерживает всякие фокусы типа:
  -+-2=2, а также выражение -2 следует писать как (0-1)*2

  DmitryDim1983@Inbox.ru
  3 декабря 2007 г.
*/

/*
 * Пока есть ещё символы для чтения:
 * - читаем очередной символ;
 * - если символ является числом, добавляем его к выходной строке;
 * - если символ является символом функции или открывающейся скобкой, помещаем его в стек;
 * - если символ является закрывающей скобкой:
 *      до тех пор, пока верхним элементом стека не станет открывающая скобка, выталкиваем элементы
 *      из стека в выходную строку. При этом открывающая скобка удаляется из стека, но в выходную
 *      строку не добавляется. Если после этого шага на вершине стека оказывается символ функции,
 *      выталкиваем его в выходную строку. Если стек закончился раньше, чем мы встретили открывающую
 *      скобку, это означает, что в выражении либо неверно поставлен разделитель, либо не
 *      согласованы скобки.
 * - если символ является оператором о1, тогда:
 *      1) пока приоритет o1 меньше либо равен приоритету оператора, находящегося
 *      на вершине стека - выталкиваем верхние элементы стека в выходную строку;
 *      2) помещаем оператор o1 в стек. Когда входная строка закончилась, выталкиваем все символы из
 *      стека в выходную строку. В стеке должны были остаться только символы операторов;
 *      если это не так, значит в выражении не согласованы скобки.
 */

#include "rpncalc.h"

#include <vector>
#include <algorithm>
#include <stack>
#include <sstream>

bool isoperator(char symbol)
{
    const vector<char> operators = {'(', '^', '*', '/', '+', '-', ')'};

    if (find(operators.begin(), operators.end(), symbol) != operators.end()) {
        return true;
    }
    return false;
}

bool isfunction(const string &function, bool caseSensitive = false)
{
    // TODO: unused parameter 'caseSensitive'
    static_cast<void>(caseSensitive);
    //

    const vector<string> functions = {"SQRT", "SIN", "COS", "TAN", "COTAN", "ARCSIN", "ARCCOS",
                                      "ARCTAN", "EXP", "LOGD", "LOG", "FACTR"};

    if (find(functions.begin(), functions.end(), function) != functions.end()) {
        return true;
    }
    return false;
}

template <typename T>
string numberToString(T Number)
{
    ostringstream ss;
    ss << Number;
    return ss.str();
}

template<typename T>
T stringToNumber(const string &number)
{
    T valor;

    std::stringstream stream(number);
    stream >> valor;
    if (stream.fail()) {
        // TODO: throw exception
        //runtime_error e(number);
        //throw e;
    }
    return valor;
}

uint32_t factorial(uint32_t n)
{
    uint32_t ret = 1;
    for (uint32_t i = 1; i <= n; ++i) {
        ret *= i;
    }
    return ret;
}

// Знаки '+', '-' не учитываются.
// Если строка str содержит один из этих знаков, то возвращается false
bool isnumber(const string &str, char decimalMark = '.')
{
    string items = "0123456789";
    items.append(string(1, decimalMark));

    return (str.find_first_not_of(items) == str.npos);
}
//

int getPriority(const string &item)
{
    if (isfunction(item)) {
        return 4;
    } else if (item == "^") {
        return 3;
    } else if (item == "*" || item == "/") {
        return 2;
    } else if (item == "+" || item == "-") {
        return 1;
    }
    return 0;
}

void strToInfix(const string &str, vector<string> &infix, char decimalMark = '.')
{
    bool inNumber = false;
    bool inWord = false;

    for (int i = 0; i < static_cast<int>(str.length()); i++) {
        char ch = str.at(i);

        if (isdigit(ch) || (ch == decimalMark)) {

            if (inNumber) {
                infix.back() += string(1, ch);
            } else {
                infix.push_back(string(1, ch));
                inNumber = true;
            }
            inWord = false;

        } else if (isoperator(ch)) {

            infix.push_back(string(1, ch));
            inNumber = false;
            inWord = false;

        } else if (isalpha(ch)) {

            if (inWord) {
                infix.back() += string(1, ch);
            } else {
                infix.push_back(string(1, ch));
                inWord = true;
            }
            inNumber = false;

        }
    }
}

void infixToPostfix(const vector<string> &infix, vector<string> &postfix)
{
    stack<string> st;

    for (int i = 0; i < static_cast<int>(infix.size()); i++) {
        string item = infix.at(i);

        if (isnumber(item)) {

            postfix.push_back(item);

        } else if (item == "(" || isfunction(item)) {

            st.push(item);

        } else if (item == ")") {

            while (!st.empty() && (st.top() != "(")) {
                postfix.push_back(st.top());
                st.pop();
            }
            // pop symbol "("
            st.pop();
            //

            // pop symbol function
            if (!st.empty() && isfunction(st.top())) {
                postfix.push_back(st.top());
                st.pop();
            }
            //

        } else if (isoperator(item.c_str()[0])) {

            while (!st.empty() && (getPriority(item) <= getPriority(st.top()))) {
                postfix.push_back(st.top());
                st.pop();
            }
            st.push(item);

        }
    }

    for (int i = 0; i < static_cast<int>(st.size()); i++) {
        postfix.push_back(st.top());
        st.pop();
    }
}

double calcPostfix(const vector<string> &postfix)
{
    stack<double> st;

    for (int i = 0; i < static_cast<int>(postfix.size()); i++) {
        string item = postfix.at(i);

        if (isnumber(item)) {

            st.push(stringToNumber<double>(item));

        } else if (item == "^") {

            double value2 = st.top();
            st.pop();

            double value1 = st.top();
            st.pop();

            st.push(pow(value1, value2));

        } else if (item == "*") {

            double value2 = st.top();
            st.pop();

            double value1 = st.top();
            st.pop();

            st.push(value1 * value2);

        } else if (item == "/") {

            double value2 = st.top();
            if (value2 == 0.0) {
                // TODO: throw exception "error: zero devisor"
                break;
            }
            st.pop();

            double value1 = st.top();
            st.pop();

            st.push(value1 / value2);

        } else if (item == "+") {

            double value2 = st.top();
            st.pop();

            double value1 = st.top();
            st.pop();

            st.push(value1 + value2);

        } else if (item == "-") {

            double value2 = st.top();
            st.pop();

            double value1 = st.top();
            st.pop();

            st.push(value1 - value2);

        } else if (item == "SQRT") {

            double value2 = st.top();
            st.pop();

            st.push(sqrt(value2));

        } else if (item == "SIN") {

            double value2 = st.top();
            st.pop();

            st.push(sin(value2));

        } else if (item == "COS") {

            double value2 = st.top();
            st.pop();

            st.push(cos(value2));

        } else if (item == "TAN") {

            double value2 = st.top();
            st.pop();

            st.push(tan(value2));

        } else if (item == "COTAN") {

            double value2 = st.top();
            st.pop();

            st.push(1 / tan(value2));

        } else if (item == "ARCSIN") {

            double value2 = st.top();
            st.pop();

            st.push(asin(value2));

        } else if (item == "ARCCOS") {

            double value2 = st.top();
            st.pop();

            st.push(acos(value2));

        } else if (item == "ARCTAN") {

            double value2 = st.top();
            st.pop();

            st.push(atan(value2));

        } else if (item == "EXP") {

            double value2 = st.top();
            st.pop();

            st.push(exp(value2));

        } else if (item == "LOGD") {

            double value2 = st.top();
            st.pop();

            st.push(log10(value2));

        } else if (item == "LOG") {

            double value2 = st.top();
            st.pop();

            st.push(log(value2));

        } else if (item == "FACTR") {

            double value2 = st.top();
            st.pop();

            st.push(factorial(value2));

        } else {
            // TODO: throw exception "error: unknow command"
        }

    }
    double res = st.top();
    st.pop();

    return res;
}

double calculate(const string &str)
{
    vector<string> infix;
    strToInfix(str, infix);

    vector<string> postfix;
    infixToPostfix(infix, postfix);

    double r = calcPostfix(postfix);

    return r;
}
