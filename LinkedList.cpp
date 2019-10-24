//
// Created by carte on 10/24/2019.
//

#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::LinkedList(const LinkedList &list) {

}

LinkedList::~LinkedList() {

}

void LinkedList::append(int item) {
    if(head == nullptr){
        head = new Node(item);
        size++;
    }
    else{
        Node* current = head;
        while(current->next != nullptr){
            current = current->next;
        }
        current -> next = new Node(item);
        size++;
    }
}

void LinkedList::InsertionSort(Node& node) {
    int i = 1;
    while(i < size){

    }
}