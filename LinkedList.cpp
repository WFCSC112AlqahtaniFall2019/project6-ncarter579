//
// Created by carte on 10/24/2019.
//

//472

#include "LinkedList.h"
using namespace std;
#include <iostream>

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::LinkedList(const LinkedList &list) {
    cout << "Copy constructor called" << endl;

    Node* listCurr = list.head; // Head of original list
    Node* listCopy = head; // Head of other list
    while(listCurr->next != nullptr){
        listCopy->next = new Node(listCurr->next->value);
        listCopy = listCopy->next;
        listCurr = listCurr ->next;
    }
}

LinkedList &LinkedList::operator=(const LinkedList &assignment) {
   cout << "Copy Assignment Operator Called" << endl;

   LinkedList obj;
   swap(obj.head, head);
   return *this;
}

LinkedList::~LinkedList() {
    cout << "Destructor called." << endl;
    Node* curr = head;
    Node* after = curr->next;
    while(curr->next != nullptr){
        delete(curr);
        curr = after;
        after = after->next;
    }
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

void LinkedList::InsertionSort() {
    Node *curr = head->next;
    Node *prev = head;
    Node *check = head;
    if (head->next == nullptr || curr->next == nullptr) {   //checking to see if their are any values in the list or only 1 value in the list
        cout << "Not enough values in the list" << endl;  //if their are not enough values print this and return
        return;
    }
    while (curr != nullptr) {    //do this until curr reaches nullPtr
        if (curr->value > prev->value) {    //if the current value is greater then the prev value move curr and prev forward 1
            curr = curr->next;  //moving curr and prev forward in the list
            prev = prev->next;
        } else {         //do this if the values need to be rearranged
            if (head->value > curr->value) {      //if head's value is greater then curr's value
                prev->next = curr->next;      //sets prev's next equal to curr's next
                curr->next = nullptr;       //set's curr's next equal to nullPtr because it is no longer used
                curr->next = head;     //sets curr's next equal to the head
                head = curr;            //sets curr's value equal to head
            } else {
                check = head;     //set check equal to head
                while (check != nullptr && check->next->value < curr->value) {   //while check dosn't reach the end of the list and checks next value is less then curr's value
                    check = check->next;   //iterate check through the list
                }
                prev->next = curr->next;     //when it reaches a value that must be swapped set prev's next equal to curr's next
                curr->next = nullptr;       //set curr's next equal to nullPtr because its no longer needed
                curr->next = check->next;     //set curr's next equal to check's next
                check->next = curr;              //set check's next equal to curr
            }
        }
        curr = prev->next;     //iterates curr
    }
}

void LinkedList::print() {
    Node * cursor = head;
    while ( cursor != nullptr ){
        cout << cursor->value << " ";
        cursor = cursor -> next ;
    }
}









    /*
    int i = 1;
    Node* temp;
    Node* curr;
    curr = head->next;
    while(i < size){
        temp = head->next;
        curr = head->next;
        if(temp->value > curr->value ){

        }
    }
     */
