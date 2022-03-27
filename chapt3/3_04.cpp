#include <bits/stdc++.h>
using namespace std;

int main( )
{
    const int seq_size = 18;
    int elem_seq[seq_size] = {
        1, 2, 3,    // Fibonacci
        3, 4, 7,    // Lucas
        2, 5, 12,   // Pell
        3, 6, 10,   // Triangular
        4, 9, 16,   // Square
        5, 12, 22   // Pentagonal
    };
    vector<int> fibonacci(elem_seq, elem_seq+3);
    vector<int> Pell(elem_seq+6, elem_seq+9);
    vector<int> fib_plus_pell(3);
    
    transform(fibonacci.begin(), fibonacci.end(),
            Pell.begin(), fib_plus_pell.begin(), plus<int>());
    
    for (int index = 0; index < fib_plus_pell.size(); index++)
        cout << fib_plus_pell[index] << " ";
    cout << endl;
  
    return 0;
}

