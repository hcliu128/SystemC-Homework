#include <iostream>
#include "Node.h"

using namespace std;

Node::Node()
{
    _Node = NULL;
}

Node::Node(unsigned int _length)
{
    if (_length <= 0)
        _Node = NULL;
    else
        _Node = (long *)malloc(_length * sizeof(long));
    // _Node = new long[_length];
}

Node::~Node()
{
    if (_Node != NULL)
    {
        free(_Node);
        _Node = NULL;
    }
}

long *Node::reCreate(unsigned int _length)
{
    free(_Node);
    _Node = (long *)malloc(_length * sizeof(long));
    return _Node;
}

int Node::setElement(unsigned int pos, long val)
{
    _Node[pos] = val;
    return 1;
}
