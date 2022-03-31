#include "Triangular.hpp"

int sum(const Triangular & trian);

int main()
{
    Triangular tri1(4);
    Triangular tri2;

    cout << tri1 << ", sum = " << sum(tri1) << endl;
    cin >> tri2;
    
    cout << tri2 << ", sum = " << sum(tri2) << endl;
    return 0;
}

int sum(const Triangular & trian)
{
    if(!trian.length())
        return 0;
    int val, sum = 0;
    trian.next_reset();
    while(trian.next(val))
        sum += val;
    
    return sum;
}