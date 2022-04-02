#include "num_sequence.hpp"

class Fibonacci : public num_sequence
{
public:
    Fibonacci(int len = 1, int beg_pos = 1) : _length(len), _beg_pos(beg_pos) {}
    virtual int elem(int pos) const;
    virtual const char *what_am_i() const { return "Fibonacci"; }
    virtual ostream &print(ostream &os = cout) const;
    int length() const { return _length; }
    int beg_pos() const { return _beg_pos; }

protected:
    virtual void gen_elems(int pos) const;
    int _length;
    int _beg_pos;
    static vector<int> _elems;
};

vector<int> Fibonacci::_elems;

int Fibonacci::elem(int pos) const
{
    if (!check_integrity(pos, _elems.size()))
        return 0;
    if (pos > _elems.size())
        Fibonacci::gen_elems(pos);
    return _elems[pos - 1];
}

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

ostream & Fibonacci::print(ostream &os) const
{
    int elem_pos = _beg_pos - 1;
    int end_pos = elem_pos + _length;
    // [elem_pos, end_pos)

    if(end_pos > _elems.size())
        Fibonacci::gen_elems(end_pos);

    os << "( "<< _beg_pos << ", " << _length << " ) ";
    while(elem_pos < end_pos)
        os << _elems[elem_pos++] << ' ';
    return os;
}
