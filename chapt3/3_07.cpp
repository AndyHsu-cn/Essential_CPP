#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
    string word;
    vector<string> text;

    while(cin >> word)
        text.push_back(word);
    for (int index = 0; index < text.size(); index++)
        cout << text[index] << endl;
    cout << "-----------------------" << endl;

    sort(text.begin(), text.end());
    for (int index = 0; index < text.size(); index++)
        cout << text[index] << endl;
    cout << "-----------------------" << endl;
    
    return 0;
}