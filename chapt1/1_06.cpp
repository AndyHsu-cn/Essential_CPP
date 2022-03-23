#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string name;
    int num_tries;
    int num_rights;
    ifstream infile("1_05.txt");

    if (!infile)
    {
        cerr << "Oops, unable to open file!" << endl;
    }else
    {
        infile >> name >> num_tries >> num_rights;
        cout << "name: " << name << endl;
        cout << "tot: " << num_tries << endl;
        cout << "right: " << num_rights << endl;
    }
    

    return 0;
}