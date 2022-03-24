#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void display_message(const string & msg, const vector<T> &vec)
{
    cout << msg << endl;
    for (int index = 0; index < vec.size(); index++)
        cout << vec[index] << endl;
}

int main(void)
{
    string msg = "Hello, andy";
    vector<int> ivec;
    vector<string> svec;
    
    ivec.push_back(1);
    ivec.push_back(2);
    svec.push_back("bnu");
    svec.push_back("hsu");

    display_message(msg, ivec);
    display_message(msg, svec);
    return 0;
}