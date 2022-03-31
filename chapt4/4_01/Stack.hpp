#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Stack
{
private:
    vector<string> _stack;
public:
    bool push(const string &elem);
    bool pop(string &elem);
    bool peek(string &elem);
    bool empty() {return _stack.empty();}
    bool full() {return _stack.max_size() == _stack.size();}
    int size(){return _stack.size();}
};