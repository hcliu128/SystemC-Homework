#include "HalfAdder.h"

void HalfAdder::prc_HalfAdder()
{
    Sum.write(A.read() ^ B.read());
    Carry.write(A.read() & B.read());
}