#ifndef LIST
#define LIST

#include "Node.h"
#include <iostream>

using namespace std;

template <class T>
class List : public Node<T>
{
protected:
    unsigned int length;

public:
    List();
    List(unsigned int _length);
    ~List();
    List(const List<T> &other);

    int setLength(unsigned int);
    unsigned int getLength();
    int setElement(unsigned int, T);
    T getElement(unsigned int);

    List<T> &operator=(const List &);
    inline bool operator==(const List<T> &);
    template <class U>
    friend ostream &operator<<(ostream &, List<U>);
};

template <class T>
List<T>::List() : Node<T>()
{
    length = 0;
    Node<T>();
}

template <class T>
List<T>::List(unsigned int _length) : Node<T>(_length)
{
    length = _length;
    Node<T>(length);
}

template <class T>
List<T>::~List()
{
    length = 0;
}

template <class T>
List<T>::List(const List &other)
{
    length = other.length;
    if (length > 0)
    {
        this->reCreate(length);
        for (unsigned int i = 0; i < length; i++)
        {
            this->_Node[i] = other._Node[i];
        }
    }
    else
    {
        this->_Node = NULL;
        length = 0;
    }
}

template <class T>
int List<T>::setLength(unsigned int new_length)
{
    if (length == 0)
    {
        this->reCreate(new_length);
        length = new_length;
        return 1;
    }
    else
    {
        cout << "List is not empty. Cannot execute "
             << "'''setLength()''' ! " << endl;
        return 0;
    }
}

template <class T>
unsigned int List<T>::getLength()
{
    return length;
}

template <class T>
int List<T>::setElement(unsigned int pos, T val)
{
    if (pos < length)
    {
        this->_Node[pos] = val;
        return 1;
    }
    else
    {
        cout << "Index out of range. Cannot execute "
             << "'''setElement()''' ! " << endl;
        return 0;
    }
}

template <class T>
T List<T>::getElement(unsigned int pos)
{
    if (pos < length)
    {
        return this->_Node[pos];
    }
    else
    {
        cout << "Index out of range. Cannot execute "
             << "'''getElement()''' ! " << endl;
        return 0;
    }
}

template <class T>
List<T> &List<T>::operator=(const List &other)
{
    if (this != &other)
    {
        if (length != other.length)
        {
            free(this->_Node);
            length = other.length;
            if (length > 0)
            {
                this->_Node = (T *)malloc(length * sizeof(T));
                for (unsigned int i = 0; i < length; i++)
                {
                    this->_Node[i] = other._Node[i];
                }
            }
            else
            {
                this->_Node = NULL;
            }
        }
        else
        {
            for (unsigned int i = 0; i < length; i++)
            {
                this->_Node[i] = other._Node[i];
            }
        }
    }
    return *this;
}

template <class T>
inline bool List<T>::operator==(const List &other)
{
    if (length != other.length)
    {
        return false;
    }
    else
    {
        for (unsigned int i = 0; i < length; i++)
        {
            if (this->_Node[i] != other._Node[i])
            {
                return false;
            }
        }
        return true;
    }
}

template <class U>
ostream &operator<<(ostream &os, List<U> list)
{
    for (unsigned int i = 0; i < list.length; i++)
    {
        os << list._Node[i] << " ";
    }
    return os;
}

#endif