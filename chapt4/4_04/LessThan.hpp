#include <iostream>
#include <algorithm>
using namespace std;

class LessThan
{
public:
    LessThan(int val): _val(val) {}
    int com_val() const {return _val;}
    void com_val(int nval) {_val = nval;}

    inline bool operator()(int value) const;
private:
    int _val;
};

bool LessThan::operator()(int value) const
{
    return value < _val;
}