#include <iostream>
#include <map>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    map<string, int> words;
    map<string, int>::iterator it;
    ofstream out_file("data.txt");
    string tword;
    while (cin >> tword)
    {
        words[tword]++;
    }
 
    if(!out_file)
        cerr << "Unable to use data.txt" << endl;
    else
    {
        for( it = words.begin(); it != words.end(); it++)
            out_file << it->first << "[" << it->second << "]" << endl;
    }
    return 0;
}