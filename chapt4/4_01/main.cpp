#include "Stack.hpp"

void fill_stack(Stack &stack, istream &is = cin)
{
    string str;
    while(is >> str && !stack.full())
        stack.push(str);
    cout << "Read in " << stack.size() << " elements\n";
}

int main()
{
    Stack s;
    string str;

    cout << "s.size() = " << s.size() << endl;
    fill_stack(s);
    cout << "s.size() = " << s.size() << endl;
    cout << "s.peek(str) = " << s.peek(str) << " ["<< str << "]"<< endl;
    return 0;
}