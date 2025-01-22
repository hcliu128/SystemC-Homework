#include "FIR.h"
#include <fstream>

int sc_main(int argc, char *argv[])
{
    // signals
    sc_signal<bool> rst("rst");
    sc_signal<sc_uint<32>> x("x");
    sc_signal<sc_uint<32>> y32("y32");
    sc_signal<sc_uint<32>> y48("y48");
    // clk for 200MHz clock
    sc_clock clock("clock", 5, SC_NS);
    // instantiate
    FIR FIR32("FIR32", 32); // with 32 taps
    FIR FIR48("FIR48", 48); // with 48 taps
    // bindings for FIR32
    FIR32.x(x);
    FIR32.y(y32);
    FIR32.clk(clock);
    FIR32.rst(rst);
    // bindings for FIR48
    FIR48.x(x);
    FIR48.y(y48);
    FIR48.clk(clock);
    FIR48.rst(rst);
    // Trace file
    sc_trace_file *tf = sc_create_vcd_trace_file("RESULT");
    // tf->set_time_unit(1, SC_PS);
    sc_trace(tf, clock, "clk");
    sc_trace(tf, rst, "rst");
    sc_trace(tf, x, "x");
    sc_trace(tf, y32, "y32");
    sc_trace(tf, y48, "y48");

    // start simulation
    rst.write(0);
    sc_start(10, SC_NS);
    rst.write(1);
    sc_start(10, SC_NS);

    // Load input data from file
    ifstream infile("firData");
    if (!infile)
    {
        cerr << "Error: Could not open input file firData."
             << endl;
        return -1;
    }

    sc_uint<32> input_val;
    for (unsigned int i = 0; i < 48; i++)
    {
        infile >> input_val;
        x.write(input_val);
        sc_start(5, SC_NS); // Wait for one clock cycle
    }
    cout << "Completed in reading file." << endl;
    rst.write(0);
    x.write(0);
    sc_start(5, SC_NS); // Wait for one clock cycle
    infile.close();

    sc_close_vcd_trace_file(tf);
    cout << "See the output file  '''RESULT.vcd'''" << endl;
    return 0;
}