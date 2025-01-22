#ifndef NODE
#define NODE

class Node
{
protected:
    long *_Node;

public:
    Node();
    Node(unsigned int);
    ~Node();
    long *reCreate(unsigned int);
    int setElement(unsigned int, long); // corresponding to the setElement() function in List
};
#endif