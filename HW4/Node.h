#ifndef NODE
#define NODE

#include <cstddef>

template <class T>
class Node
{
protected:
    T *_Node;

public:
    Node();
    Node(unsigned int);
    ~Node();
    T *reCreate(unsigned int);
    int setElement(unsigned int, long);
    // corresponding to the setElement() function in List
};

template <class T>
Node<T>::Node()
{
    _Node = NULL;
}

template <class T>
Node<T>::Node(unsigned int _length)
{
    if (_length <= 0)
        _Node = NULL;
    else
        _Node = new T[_length];
}

template <class T>
Node<T>::~Node()
{
    if (_Node != NULL)
    {
        delete[] _Node;
        _Node = NULL;
    }
}

template <class T>
T *Node<T>::reCreate(unsigned int _length)
{
    delete[] _Node;
    _Node = new T[_length];
    return _Node;
}
#endif