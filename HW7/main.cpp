#include "systemc.h"
#include "FullAdder.h"

int sc_main(int argc, char *argv[])
{
    sc_signal<bool> A, B, Cin, S, Cout, Sum, Carry;
    FullAdder fa("fa");
    fa.A(A);
    fa.B(B);
    fa.Cin(Cin);
    fa.S(S);
    fa.Cout(Cout);

    HalfAdder ha("ha");
    ha.A(A);
    ha.B(B);
    ha.Sum(Sum);
    ha.Carry(Carry);

    sc_trace_file *tf = sc_create_vcd_trace_file("RESULT");
    sc_trace(tf, A, "FA-A");
    sc_trace(tf, B, "FA-B");
    sc_trace(tf, Cin, "Cin");
    sc_trace(tf, S, "S");
    sc_trace(tf, Cout, "Cout");
    // half adder
    sc_trace(tf, A, "HA-A");
    sc_trace(tf, B, "HA-B");
    sc_trace(tf, Sum, "Sum");
    sc_trace(tf, Carry, "Carry");

    A = 0;
    B = 0;
    Cin = 0;
    sc_start(1, SC_NS);
    A = 0;
    B = 0;
    Cin = 1;
    sc_start(1, SC_NS);
    A = 0;
    B = 1;
    Cin = 0;
    sc_start(1, SC_NS);
    A = 0;
    B = 1;
    Cin = 1;
    sc_start(1, SC_NS);
    A = 1;
    B = 0;
    Cin = 0;
    sc_start(1, SC_NS);
    A = 1;
    B = 0;
    Cin = 1;
    sc_start(1, SC_NS);
    A = 1;
    B = 1;
    Cin = 0;
    sc_start(1, SC_NS);
    A = 1;
    B = 1;
    Cin = 1;
    sc_start(1, SC_NS);

    sc_close_vcd_trace_file(tf);
    return 0;
}