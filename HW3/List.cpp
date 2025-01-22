#include <iostream>
#include "List.h"

using namespace std;

List::List() : Node()
{
    length = 0;
}

List::List(unsigned int _length) : Node()
{
    length = _length;
    if (length > 0)
    {
        _Node = new long[length];
    }
    else
    {
        _Node = nullptr;
    }
}

List::~List()
{
    length = 0;
}

List::List(const List &other)
{
    length = other.length;
    if (length > 0)
    {
        this->reCreate(length);
        for (unsigned int i = 0; i < length; i++)
        {
            _Node[i] = other._Node[i];
        }
    }
    else
    {
        _Node = NULL;
    }
}

List &List::operator=(const List &other)
{
    if (this != &other)
    {
        length = other.length;
        this->reCreate(length);
        for (unsigned int i = 0; i < length; i++)
        {
            _Node[i] = other._Node[i];
        }
    }
    return *this;
}

int List::setLength(unsigned int new_length)
{
    if (length == 0)
    {
        reCreate(new_length);
        length = new_length;
        return 1;
    }
    else
    {
        cout << "Error in int List::setLength(unsigned int new_length);"
             << endl;
        return 0;
    }
}

int List::setElement(unsigned int pos, long val)
{
    if (pos < length)
    {
        return Node::setElement(pos, val);
    }
    else
    {
        cout << "Error in int List::setElement(unsigned int pos, long val);"
             << endl;
        return 0;
    }
}

long List::getElement(unsigned int pos)
{
    if (pos < length)
        return _Node[pos];
    else
    {
        cout << "Error in long List::getElement(unsigned int pos);"
             << endl;
        return -99999;
    }
}

List List::operator+(const List &other)
{
    unsigned int loop =
        (length > other.length) ? length : other.length;
    List temp(loop);
    for (unsigned int i = 0; i < loop; i++)
    {
        temp.setElement(i, _Node[i] + other._Node[i]);
    }
    return temp;
}

List &List::operator+=(const List &other)
{
    unsigned int loop =
        (length > other.length) ? length : other.length;
    for (unsigned int i = 0; i < loop; i++)
    {
        _Node[i] += other._Node[i];
    }
    return *this;
}

List List::operator++() // prefix++
{
    for (unsigned int i = 0; i < length; i++)
    {
        ++_Node[i];
    }
    return *this;
}

List List::operator++(int dummy) // postfix++
{
    List temp(*this);
    for (unsigned int i = 0; i < length; i++)
    {
        _Node[i]++;
    }
    return temp;
}

List List::operator--() // prefix
{
    for (unsigned int i = 0; i < length; i++)
    {
        --_Node[i];
    }
    return *this;
}

List List::operator--(int dummy) // postfix
{
    List temp(*this);
    for (unsigned int i = 0; i < length; i++)
    {
        _Node[i]--;
    }
    return temp;
}

ostream &operator<<(ostream &out, List &list)
{
    for (unsigned int i = 0; i < list.length; i++)
    {
        out << list._Node[i] << " ";
    }
    out << endl;
    return out;
}

istream &operator>>(istream &in, List &list)
{
    for (unsigned int i = 0; i < list.length; i++)
    {
        in >> list._Node[i];
    }
    return in;
}
