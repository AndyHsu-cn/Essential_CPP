#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool grow_vec(vector<int> & vec, int elem)
{
    while(vec.back() < elem)
    {
        vec.push_back(vec.back() + vec[vec.size() - 2]);
    }
    if(vec.back() == elem)
        return true;
    else
        return false;
}

bool is_elem( vector<int> & vec, int elem)
{
    // int max_value = *max_element(vec.begin(), vec.end());
    int max_value = vec.empty() ? 0: vec.back();
    if(max_value < elem)
        return grow_vec(vec, elem);
    else if(max_value == elem)
        return true;
    else
        return binary_search(vec.begin(), vec.end(), elem);
}

int main(void)
{
    int arr[6] = {1, 1, 2, 3, 5, 8};
    vector<int> seq_vec(arr, arr+6);
    cout << "is_elem(seq_vec, 3): " << is_elem(seq_vec, 3) << endl;
    cout << "is_elem(seq_vec, 4): " << is_elem(seq_vec, 4) << endl;
    cout << "is_elem(seq_vec, 21): " << is_elem(seq_vec, 21) << endl;
    cout << "is_elem(seq_vec, 22): " << is_elem(seq_vec, 22) << endl;
    cout << "last number of seq: " << seq_vec.back() << endl;
    return 0;
}