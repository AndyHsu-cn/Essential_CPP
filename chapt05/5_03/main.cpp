#include "fibonacci.hpp"

ostream & operator<<(ostream &os, const num_sequence &ns)
{
    return ns.print(os);
}
int main()
{
    Fibonacci fib;
    cout << fib << endl;

    Fibonacci fib2(16);
    cout << fib2 << endl;

    num_sequence * pns = new Fibonacci(8, 12);
    cout << *pns << endl;

    return 0;
}