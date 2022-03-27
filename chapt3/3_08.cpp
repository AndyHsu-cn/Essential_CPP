#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <fstream>
using namespace std;

int main()
{
    ifstream in_file("input.txt");
    ofstream out_file("output.txt");
    istream_iterator<string> is(in_file);
    istream_iterator<string> eof;
    ostream_iterator<string> os(out_file, "\n");
    vector<string> text;
    
    if(!in_file || !out_file)
    {
        cerr << "Unable to use files" << endl;
        return -1;
    }
    copy(is, eof, back_inserter(text));
    sort(text.begin(), text.end());

    copy(text.begin(), text.end(), os);
    return 0;
}