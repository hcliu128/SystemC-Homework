#include "systemc.h"
#include "HalfAdder.h"

SC_MODULE(FullAdder)
{
    sc_in<bool> A, B, Cin;
    sc_out<bool> S, Cout;
    sc_signal<bool> S1, C1, C2;

    void prc_full_adder();

    HalfAdder *ha1;
    HalfAdder *ha2;

    SC_CTOR(FullAdder)
    {
        ha1 = new HalfAdder("ha1");
        ha1->A(A);
        ha1->B(B);
        ha1->Sum(S1);
        ha1->Carry(C1);

        ha2 = new HalfAdder("ha2");
        ha2->A(S1);
        ha2->B(Cin);
        ha2->Sum(S);
        ha2->Carry(C2);

        SC_METHOD(prc_full_adder);
        sensitive << S1 << C1 << C2;
    }
};