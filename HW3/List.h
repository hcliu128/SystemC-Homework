#ifndef LIST
#define LIST

#include <iostream>
#include "Node.h"

class List : Node
{
protected:
    unsigned int length;

public:
    List();
    List(unsigned int _length);
    ~List();
    List(const List &other);

    int setLength(unsigned int);
    int setElement(unsigned int, long);
    long getElement(unsigned int);

    List &operator=(const List &);
    List operator+(const List &);
    List &operator+=(const List &);
    List operator++();
    List operator++(int);
    List operator--();
    List operator--(int);

    friend std::ostream &operator<<(std::ostream &, List &);
    friend std::istream &operator>>(std::istream &, List &);
};

#endif