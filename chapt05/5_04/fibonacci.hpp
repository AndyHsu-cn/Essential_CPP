#include "num_sequence.hpp"

class Fibonacci : public num_sequence
{
public:
    virtual const char *what_am_i() 
    {
         return "Fibonacci"; 
    }
};