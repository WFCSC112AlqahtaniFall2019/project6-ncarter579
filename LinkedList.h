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
    LinkedList(const LinkedList &list);  //copy constructor
    ~LinkedList();    //destructor
    LinkedList& operator= ( const LinkedList &assignment );  //copy assignment operator
    void append(int item);
    void InsertionSort();
    void print();

private:
    Node * head;   //head of the list
    int size = 0;


};