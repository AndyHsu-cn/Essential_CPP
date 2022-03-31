#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

class Triangular_iterator
{
public:
    Triangular_iterator(int index) : _index(index) {}
    bool operator==(const Triangular_iterator &) const;
    bool operator!=(const Triangular_iterator &) const;
    int operator*() const;
    Triangular_iterator &operator++();
    Triangular_iterator operator++(int);

private:
    int _index;
    void check_integrity() const;
};

class Triangular
{
    friend class Triangular_iterator;

public:
    typedef Triangular_iterator iterator;
    Triangular(int len = 1, int begin = 1);
    int length() const { return _length; }
    void length(int len) {_length = len; }
    int beg_pos() const { return _beg_pos; }
    void beg_pos(int pos) {_beg_pos = pos;}
    int elem(int pos) const;
    bool next(int &val) const;
    void next_reset() const { _next = _beg_pos - 1; }
    Triangular &copy(const Triangular &rhs);

    static bool is_elem(int value);
    static void gen_elements(int length);
    static void gen_elems_to_value(int value);
    static void display(int length, int beg_pos, ostream &os = cout);
    static int cur_size()
    {
        return _elems.size();
    }

    Triangular_iterator begin() const
    {
        return Triangular_iterator(_beg_pos);
    }

    Triangular_iterator end() const
    {
        return Triangular_iterator(_beg_pos + _length);
    }

private:
    int _length;       // 元素个数
    int _beg_pos;      // 起始位置
    mutable int _next; // 下一个元素的索引

    static vector<int> _elems;
    static const int _max_elems = 1024;
};

// Triangular_iterator方法实现
bool Triangular_iterator::operator==(const Triangular_iterator &rhs) const
{
    return _index == rhs._index;
}

bool Triangular_iterator::operator!=(const Triangular_iterator &rhs) const
{
    return !(*this == rhs);
}

int Triangular_iterator::operator*() const
{
    check_integrity();
    return Triangular::_elems[_index - 1];
}

void Triangular_iterator::check_integrity() const
{
    if (_index >= Triangular::_max_elems)
        // throw iterator_overflow();              // 抛出异常

        if (_index >= Triangular::_elems.size())
            Triangular::gen_elements(_index + 1);
}

Triangular_iterator &Triangular_iterator::operator++()
{
    ++_index;
    check_integrity();
    return *this;
}

Triangular_iterator Triangular_iterator::operator++(int)
{
    Triangular_iterator tmp = *this;
    ++_index;
    check_integrity();
    return tmp;
}

// Triangular方法实现
vector<int> Triangular::_elems;
Triangular::Triangular(int len, int begin)
{
    _length = len > 0 ? len : 1;
    _beg_pos = begin > 0 ? begin : 1;
    _next = _beg_pos - 1;

    int elem_cnt = _beg_pos + _length - 1; // Triangular中已经计算出的元素个数
    if (_elems.size() < elem_cnt)
        gen_elements(elem_cnt);
}

int Triangular::elem(int pos) const
{
    return _elems[pos - 1];
}

bool Triangular::next(int &val) const
{
    if (_next < _beg_pos + _length - 1)
    {
        val = _elems[_next++];
        return true;
    }
    return false;
}

Triangular &Triangular::copy(const Triangular &rhs)
{
    if (this != &rhs)
    {
        _length = rhs._length;
        _beg_pos = rhs._beg_pos;
        _next = rhs._beg_pos - 1;
    }
    return *this;
}

bool Triangular::is_elem(int value)
{
    if (!_elems.size() || _elems[_elems.size() - 1])
        gen_elems_to_value(value);

    vector<int>::iterator found_it;
    vector<int>::iterator end_it = _elems.end();
    found_it = find(_elems.begin(), end_it, value);
    return found_it != end_it;
}

void Triangular::gen_elements(int length)
{
    if (length < 0 || length > _max_elems)
        return;
    if (_elems.size() < length)
    {
        int ix = _elems.size() ? _elems.size() + 1 : 1;
        for (; ix <= length; ix++)
            _elems.push_back(ix * (ix + 1) / 2);
    }
}

void Triangular::gen_elems_to_value(int value)
{
    int ix = _elems.size();
    if (!ix)
    {
        _elems.push_back(1);
        ix = 1;
    }
    while (_elems[ix - 1] < value && ix < _max_elems)
    {
        ++ix;
        _elems.push_back(ix * (ix + 1) / 2);
    }
    if (ix == _max_elems)
        cerr << "Value too large " << value << "-- exceeds max size of " << _max_elems << endl;
}

void Triangular::display(int length, int beg_pos, ostream &os)
{
    for (int ix = beg_pos; ix < beg_pos + length; ix++)
        os << Triangular::_elems[ix - 1] << ' ';
}

ostream &operator<<(ostream &os, const Triangular &rhs)
{
    os << "( " << rhs.beg_pos() << ", " << rhs.length() << " )";
    rhs.display(rhs.length(), rhs.beg_pos(), os);
    return os;
}

istream & operator>>(istream & is, Triangular & rhs)
{
    int bp, len;
    is >> bp >> len;
    rhs.beg_pos(bp);
    rhs.length(len);
    rhs.next_reset();

    int elem_cnt = bp + len - 1;
    if (Triangular::cur_size() < elem_cnt)
        Triangular::gen_elements(elem_cnt);
    return is;
}