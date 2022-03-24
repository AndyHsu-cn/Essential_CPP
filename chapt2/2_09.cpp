#include <iostream>
using namespace std;

int add(int a, int b)
{
    return a + b;
}

int substract(int a, int b)
{
    return a - b;
}

int main()
{
    int x = 5, y = 3;
    int (*pf)(int, int);
    pf = add;
    cout << "pf point to add: " << pf(x, y) << endl;

    pf = substract;
    pf(x, y);
    cout << "pf point to substract: " << pf(x, y) << endl;

    return 0;
}