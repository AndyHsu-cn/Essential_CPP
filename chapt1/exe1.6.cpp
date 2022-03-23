#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    vector<int> ivec;
    int ival;
    int sum = 0;

    while(cin >> ival)
        ivec.push_back(ival);

    for (int index = 0; index < ivec.size(); index++)
        sum += ivec[index];
    cout << "sum = " << sum << endl;
    
    return 0;
}