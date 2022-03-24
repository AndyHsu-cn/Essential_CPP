#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector<int> * fibon_seq(int pos, istream &is , ostream &os);

int main()
{
    int pos;
    ifstream infile("fibon_seq.txt");
    ofstream outfile("fibon_seq.txt", ios_base::app);

    cout << "Please enter a position: ";
    while(cin >> pos)
    {
        if(fibon_seq(pos, infile, outfile))
        {
            
            
        }else
            cout << "Sorry, could not calculate element # " << pos << endl;
        cout << "Please enter another position: ";
    }

    return 0;
}

vector<int> * fibon_seq(int pos, istream &is, ostream & os)
{
    static vector<int> elems;
    if(pos<=0 || pos>1024)
    {
        return NULL;
    }

    for(int ix = elems.size(); ix < pos; ++ix)
    {
        if(ix==0 || ix==1)
        {
            elems.push_back(1);
            os << 1 << endl;
        }       
        else
        {
            elems.push_back(elems[ix-1] + elems[ix-2]);
            os << elems[ix-1] + elems[ix-2] << endl;
        }        
    }
    cout << endl;
    return &elems;
}