#ifndef fir
#define fir

// Include fixed-point data types
#define SC_INCLUDE_FX
#include <systemc.h>

SC_MODULE(FIR)
{
    // Ports
    sc_in<sc_uint<32>> x;  // Input
    sc_out<sc_uint<32>> y; // Output
    sc_in<bool> clk;       // Clock
    sc_in<bool> rst;       // Reset (active low)

    // Internal variables
    sc_fixed<32, 16> fb; // Coefficient
    // Delay line -> we need max(taps) + 1 amplifiers
    sc_uint<32> mid[49]; // professor says it has to be sc_signal
    unsigned int tap;    // Number of taps

    void prcFIR(); // FIR filter process

    // Constructors
    SC_CTOR(FIR, unsigned int n = 16) : tap(n)
    {
        SC_CTHREAD(prcFIR, clk.pos());
        reset_signal_is(rst, false);
    }
};

#endif // FIR
