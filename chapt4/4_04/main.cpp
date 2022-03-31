#include "LessThan.hpp"
#include <vector>

int count_less_than(const vector<int> & vec, int comp)
{
    LessThan lt(comp);
    int count = 0;
    for(int ix = 0; ix < vec.size(); ix++)
        if(lt(vec[ix]))
            ++count;
    return count;
}

void print_less_than(const vector<int> & vec, int comp, ostream &os = cout)
{
    LessThan lt(comp);
    vector<int>::const_iterator iter = vec.begin();
    vector<int>::const_iterator iter_end = vec.end();

    while((iter = find_if(iter, iter_end, lt)) != iter_end)
    {
        os << *iter << ' ';
        iter++;
    }
    cout << endl;
}

int main()
{
    int ia[16] = {17, 12, 44, 9, 18, 45, 6, 14,
                  23, 67, 9, 0, 27, 55, 8, 16};
    vector<int> ivec(ia, ia + 16);
    int comp_val = 20;

    cout << "Number of elements less than " << comp_val << " are " 
         << count_less_than(ivec, comp_val) << endl;
        
    print_less_than(ivec, comp_val);
    return 0;
}