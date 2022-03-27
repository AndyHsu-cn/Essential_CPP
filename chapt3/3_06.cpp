#include <iostream>
#include <map>
#include <set>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    string bad_words[] = { "cat", "apple", "banana", "dog"};
    map<string, int> words;
    map<string, int>::iterator it;
    set<string> word_exclusion(bad_words, bad_words+4);
    set<string>::iterator it_set;
    ofstream out_file("data.txt");
    string tword;

    // 测试set集合
    for( it_set = word_exclusion.begin(); it_set != word_exclusion.end(); it_set++)
        cout << *it_set << endl;

    while (cin >> tword)
    {
        if(word_exclusion.count(tword))
            continue;
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