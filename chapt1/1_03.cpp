#include <iostream>
#include <vector>
using namespace std;

int main()
{
    const int seq_size = 18;
    vector<int> pell_seq(seq_size);
    pell_seq[0] = 1;
    pell_seq[1] = 2;
    for (int index = 2; index < seq_size; index++)
        pell_seq[index] = 2 * pell_seq[index-1] + pell_seq[index-2];
    
    cout << "The first " << pell_seq.size() << " elements of the Pell series:" << endl;
    for (int index = 0; index < seq_size; index++)
        cout << pell_seq[index] << " ";
    cout << endl;
    
    return 0;
}