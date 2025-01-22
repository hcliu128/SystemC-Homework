#ifndef HA
#define HA
#include "systemc.h"

SC_MODULE(HalfAdder)
{
    sc_in<bool> A, B;
    sc_out<bool> Sum, Carry;

    void prc_HalfAdder();

    SC_CTOR(HalfAdder)
    {
        SC_METHOD(prc_HalfAdder);
        sensitive << A << B;
    }
};
#endif