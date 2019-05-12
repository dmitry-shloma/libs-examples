/*

  // С целью уменьшения накладных расходов, все внутренние операции выполнены через вектор

*/

#include "matrices.h"

#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <sstream>

int randFromRange(const int &min, const int &max)
{
    if (min > max) {
        return 0;
    }

    static bool first = true;
    if (first) {
        srand(time(0));
        first = false;
    }
    return (min == max ? min : min + rand() % (max - min));
}

template <typename T> string toString(const T& t)
{
    ostringstream oss;
    oss << t;
    return string (oss.str());
}
//

Matrix::Matrix()
{
    // initilize empty matrix
    rowCount_ = 0;
    colCount_ = 0;
    items_ = vector<float>();
    //
}

Matrix::Matrix(const uint &rowCount, const uint &colCount, const vector<float> &items)
{
    rowCount_ = rowCount;
    colCount_ = colCount;
    items_ = items;

    //exception
    if (rowCount_ * colCount_ != items_.size()) {
        cout << "exception" << endl;
    }
    //
}

Matrix::Matrix(const uint &rowCount, const uint &colCount, const pair<int, int> &minMaxValueRange)
{
    rowCount_ = rowCount;
    colCount_ = colCount;
    items_ = vector<float>();

    for (uint i = 0; i < rowCount_ * colCount_; i++) {
        items_.push_back(randFromRange(minMaxValueRange.first, minMaxValueRange.second));
    }
}

Matrix::~Matrix()
{
    items_.clear();
    // ?
}

float Matrix::getElementValue(const uint &row, const uint &col)
{
    // exception
    if (items_.empty()) {
        cout << "matrix is empty" << endl;
        return 0;
    }
    //

    return items_.at(row * colCount_ + col);
}

void Matrix::setElementValue(const uint &row, const uint &col, const float &value)
{
    // exception
    if (items_.empty()) {
        cout << "matrix is empty" << endl;
        return;
    }
    //

    items_.at(row * colCount_ + col) = value;
}

void Matrix::swapElementValue(const uint &row1, const uint &col1, const uint &row2, const uint &col2)
{
    // Так
    swap(items_.at(row1 * colCount_ + col1), items_.at(row2 * colCount_ + col2));
    //

    //...или так
    //float value1 = items_.at(row1 * colCount_ + col1);
    //float value2 = items_.at(row2 * colCount_ + col2);
    //setElementValue(row1, col1, value2);
    //setElementValue(row2, col2, value1);
    //
}

Matrix Matrix::add(Matrix matrix)
{
    // exception
    if (rowCount_ != matrix.rowCount_ || colCount_ != matrix.colCount_) {
        cout << "exception" << endl;
    }
    //

    vector<float> temp = vector<float>();
    for (uint i = 0; i < matrix.getItems().size(); i++) {
        temp.push_back(items_.at(i) + matrix.getItems().at(i));
    }
    return Matrix(rowCount_, colCount_, temp);
}

Matrix Matrix::subtract(Matrix matrix)
{
    // exception
    if (rowCount_ != matrix.rowCount_ || colCount_ != matrix.colCount_) {
        cout << "exception" << endl;
    }
    //

    vector<float> temp = vector<float>();
    for (uint i = 0; i < matrix.getItems().size(); i++) {
        temp.push_back(items_.at(i) - matrix.getItems().at(i));
    }
    return Matrix(rowCount_, colCount_, temp);
}

Matrix Matrix::multiplyByScalar(const float &value)
{
    vector<float> temp = vector<float>();
    for (uint i = 0; i < items_.size(); i++) {
        temp.push_back(value * items_.at(i));
    }
    return Matrix(rowCount_, colCount_, temp);
}

Matrix Matrix::toTranspose()
{
    vector<float> temp = items_;
    for (uint i = 0; i < items_.size(); i++) {
        uint row = i / colCount_;
        uint col = i % colCount_;
        temp.at(col * rowCount_ + row) = items_.at(i);
    }

    // Для возвращения транспонированной матрицы, нужно строки и столбцы поменять местами
    return Matrix(colCount_, rowCount_, temp);
}

uint Matrix::getRowCount()
{
    return rowCount_;
}

uint Matrix::getColCount()
{
    return colCount_;
}

void Matrix::outTo(string &buffer, const string &delim)
{
    if (items_.empty()) {
        cout << "matrix is empty" << endl;
        return;
    }

    buffer.clear();
    for (uint i = 0; i < items_.size(); i++) {
        buffer.append(toString(items_.at(i)));
        if ((i + 1) % colCount_) {
            buffer.append(delim);
        } else {
            buffer.append(1, '\n');
        }
    }
}

vector<float> Matrix::getItems()
{
    return items_;
}
