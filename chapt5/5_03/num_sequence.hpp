#include <iostream>
#include <vector>
using namespace std;

class num_sequence
{
public:
    virtual ~num_sequence() { }
    int elem(int pos) const;
    virtual const char *what_am_i() const = 0;
    ostream &print(ostream &os = cout) const;
    static int max_elems() { return _max_elems; };
    int length() const { return _length; }
    int beg_pos() const { return _beg_pos; }

protected:
    num_sequence(int len, int bp, vector<int> &re) : _length(len), _beg_pos(bp), _relems(re)
    {
    }
    virtual void gen_elems(int pos) const = 0;
    bool check_integrity(int pos, int size) const;
    int _length;
    int _beg_pos;
    const static int _max_elems = 1024;
    vector<int> &_relems;
};

bool num_sequence::check_integrity(int pos, int size) const
{
    if (pos <= 0 || pos > _max_elems)
    {
        cerr << "!!  invalid position: " << pos << " Cannot honor request\n";
        return false;
    }
    if (pos > size)
        gen_elems(pos);
    return true;
}

int num_sequence::elem(int pos) const
{
    if (!check_integrity(pos, _relems.size()))
        return 0;
    if (pos > _relems.size())
        gen_elems(pos);
    return _relems[pos - 1];
}

ostream &num_sequence::print(ostream &os) const
{
    int elem_pos = _beg_pos - 1;
    int end_pos = elem_pos + _length;

    if (end_pos > _relems.size())
        gen_elems(end_pos);

    os << "( " << _beg_pos << ", " << _length << " ) ";
    while (elem_pos < end_pos)
        os << _relems[elem_pos++] << ' ';
    return os;
}
