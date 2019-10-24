#ifndef NODE_H
#define NODE_H

class Node {
public:
    // Node constructor

    Node(int v = 0, Node* n = nullptr)
    {
        value = v;
        next = n;
    }
private:
    friend class LinkedList;  //creates a friend class with linked list class
    int value;
    Node* next;

};

#endif //NODE_H
