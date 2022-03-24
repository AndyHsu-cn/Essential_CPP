#include <iostream>
using namespace std;

bool fibon_elem(int pos, int &elem);

int main()
{
    int pos;
    int elem;

    cout << "Please enter a position: ";
    cin >> pos;
    if(fibon_elem(pos, elem))
    {
        cout << "element # " << pos << " : " << elem << endl;
    }else
        cout << "Sorry, could not calculate element # " << pos << endl;
    return 0;
}

bool fibon_elem(int pos, int &elem)
{
    if(pos<=0 || pos>1024)
    {
        elem = 0;
        return false;
    }
    elem = 1;
    int n1 = 1;
    int n2 = 1;
    for (int index = 3; index <= pos; index++)
    {
        elem = n1 + n2;
        n1 = n2;
        n2 = elem;
    }
    return true;
}