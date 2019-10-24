//
// Created by carte on 10/24/2019.
//

#ifndef BINARYINSERTIONSORT_LINKEDLIST_H
#define BINARYINSERTIONSORT_LINKEDLIST_H

#endif //BINARYINSERTIONSORT_LINKEDLIST_H
#include "Node.h"
class LinkedList{
public:
    LinkedList();   //constructor
    LinkedList(const LinkedList &list);
    ~LinkedList();    //destructor
    void append(int item);
    void InsertionSort(Node&);

private:
    Node * head;   //head of the list
    int size = 0;


};