#include <iostream>
using namespace std;

class Matrix
{
public:
    Matrix(){ cout << "Default constructor was called" << endl; }
    Matrix(int row, int col) : _row(row), _col(col)
    {
        cout << "Matrix(int, int) was called" << endl;
        pmat = new double[row * col];
    }

    Matrix(const Matrix & rhs): _row(rhs._row), _col(rhs._col)
    {
        cout << "Matrix(const Matrix &) was called" << endl;
        pmat = new double[_row * _col];
        for (int ix = 0; ix < _row * _col; ix++)
            pmat[ix] = rhs.pmat[ix];
    }

    Matrix & operator=(const Matrix &rhs)
    {
        cout << "copy assignment operator was called" << endl;
        if(this != &rhs)
        {
            _row = rhs._row;
            _col = rhs._col;
            pmat = new double[_row * _col];
            for(int ix = 0; ix < _row * _col; ++ix)
                pmat[ix] = rhs.pmat[ix];
        }
        return *this;
    }

    ~Matrix()
    {
        cout << "~Matrix() was called" << endl;
        delete [] pmat;
    }

private:
    int _row;
    int _col;
    double * pmat;
};