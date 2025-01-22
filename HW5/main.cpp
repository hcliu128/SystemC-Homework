#include "timer.h"

int sc_main(int argc, char *argv[])
{
    sc_signal<bool> start, timeout;
    sc_time t(10, SC_NS); // 100Mhz timer
    sc_clock clock("clock", t, 0.50, SC_ZERO_TIME, true);

    timer my_timer("my_timer");
    my_timer.start(start);
    my_timer.timeout(timeout);
    my_timer.clock(clock);

    sc_trace_file *tf = sc_create_vcd_trace_file("RESULT");
    sc_trace(tf, clock, "clock");
    sc_trace(tf, start, "start");
    sc_trace(tf, timeout, "timeout");
    sc_trace(tf, my_timer.count, "count");

    sc_start(t * 0); // start
    start.write(1);
    sc_start(t * 3);
    start.write(0);
    sc_start(t * 4); // befosre timeout
    start.write(1);  // reset
    sc_start(t * 1);
    start.write(0);
    sc_start(t * 5); // after timeout
    start.write(1);  // reset
    sc_start(t * 1);
    start.write(0);   // start
    sc_start(t * 16); // rest of time

    cout << "Timeout\n";
    sc_close_vcd_trace_file(tf);
    cout << "See the result in RESULT.vcd\n"
         << endl;
    return 0;
}