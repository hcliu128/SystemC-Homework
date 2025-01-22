#include "FIR.h"

void FIR::prcFIR()
{
    // initialize
    fb = 1.0 / (tap + 1);
    sc_uint<32> b;
    for (int i = 0; i < 32; i++) // 32-bit fixed point
    {
        b[i] = fb[i];
    }
    // Reset all internal variables
    for (unsigned int i = 0; i < tap; i++)
    {
        mid[i] = 0;
    }
    y.write(0);

    wait();
    while (true)
    {
        // Shift the delay line
        for (unsigned int i = tap; i > 0; i--)
        {
            mid[i] = mid[i - 1];
        }
        mid[0] = x.read();

        // Compute FIR filter output
        sc_uint<32> acc = 0;
        for (unsigned int i = 0; i <= tap; i++)
        {
            acc += mid[i] * b;
        }

        // Assign output
        y.write(acc);
        // cout << "y = " << y.read() << endl;
        wait();
    }
}
