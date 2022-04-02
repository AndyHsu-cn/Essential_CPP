#include "num_sequence.hpp"

class Fibonacci : public num_sequence
{
public:
    Fibonacci(int len = 1, int beg_pos = 1) : num_sequence(len, beg_pos, _elems) 
    {
    }
    virtual const char *what_am_i() const { return "Fibonacci"; }

protected:
    virtual void gen_elems(int pos) const;
    static vector<int> _elems;
};

vector<int> Fibonacci::_elems;

void Fibonacci::gen_elems(int pos) const
{
    if (_elems.empty())
    {
        _elems.push_back(1);
        _elems.push_back(1);
    }
    if (_elems.size() < pos) // 不用等号可以吗
    {
        int ix = _elems.size();
        int n_2 = _elems[ix - 2];
        int n_1 = _elems[ix - 1];
        for (; ix < pos; ++ix)
        {
            int elem = n_1 + n_2;
            _elems.push_back(elem);
            cout << "gen_elmes: " << elem << endl;
            n_2 = n_1;
            n_1 = elem;
        }
    }
}
