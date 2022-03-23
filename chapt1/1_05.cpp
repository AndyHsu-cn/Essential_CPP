#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string name;
    int num_tries;
    int num_rights;
    ofstream outfile("1_05.txt", ios_base::app);

    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your num_tries, num_rights: ";
    cin >> num_tries >>num_rights;
    if (!outfile)
    {
        cerr << "Oops, unable to save session data!" << endl;
    }else
    {
        outfile << name << ' ' 
                << num_tries << ' ' 
                << num_rights << ' ' << endl;
    }
    

    return 0;
}