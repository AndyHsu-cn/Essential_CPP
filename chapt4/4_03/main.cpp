#include "Matrix.hpp"

int main()
{
    Matrix mat1(8, 4);
    {
        Matrix mat2;
        mat2 = mat1;
    }

    cout << "Bye" << endl;
    return 0;
}