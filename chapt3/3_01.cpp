#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int arr[4] = {1, 3, 5, 7};
    vector<string> svec;
    const vector<int> ivec(arr, arr + 4);
    svec.push_back("andy");
    svec.push_back("bnu");
    svec.push_back("c++");

    vector<string>::iterator it_first = svec.begin();
    vector<int>::const_iterator ivec_first = ivec.begin();
    while(it_first != svec.end())
    {
        cout << *(it_first) << endl;
        it_first++;
    }

    cout << endl;

    while(ivec_first != ivec.end())
    {
        cout << *(ivec_first) << endl;
        ivec_first++; 
    }



    return 0;
}