#ifndef MATRICES_H
#define MATRICES_H

using namespace std;

//#include <string>

//#ifdef __cplusplus
//extern "C" {
//#endif

//double calculate(const string &str);

//#ifdef __cplusplus
//}
//#endif

#include <vector>
#include <iostream>

class Matrix
{
public:
    Matrix();
    Matrix(const uint &rowCount, const uint &colCount, const vector<float> &items);
    Matrix(const uint &rowCount, const uint &colCount, const pair<int, int> &minMaxValueRange);

    ~Matrix();

    float getElementValue(const uint &row, const uint &col);
    void setElementValue(const uint &row, const uint &col, const float &value);
    void swapElementValue(const uint &row1, const uint &col1, const uint &row2, const uint &col2);

    Matrix add(Matrix matrix);
    Matrix subtract(Matrix matrix);
    Matrix multiplyByScalar(const float &value);

    Matrix toTranspose();

    uint getRowCount();
    uint getColCount();

    void outTo(string &buffer, const string &delim = string());

protected:
    vector<float> getItems();

private:
    uint rowCount_;
    uint colCount_;
    vector<float> items_;
};

#endif // MATRICES_H
