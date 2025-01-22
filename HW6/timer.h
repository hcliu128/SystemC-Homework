#include <systemc.h>

SC_MODULE(timer)
{
    sc_in<bool> start; // ports
    sc_out<bool> timeout;
    sc_in<bool> clock;

    int count; // data and function members
    void runtimer();

    SC_CTOR(timer)
    { // constructor
        SC_CTHREAD(runtimer, clock.pos());
        async_reset_signal_is(start, true);
    }
}; // do not forget the final semi-column
