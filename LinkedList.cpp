//
// Created by carte on 10/24/2019.
//
#include "LinkedList.h"
using namespace std;
#include <iostream>

LinkedList::LinkedList() {   //default constructor sets head equal to nullPtr
    head = nullptr;
}

LinkedList::LinkedList(const LinkedList &list) {      //copy constructor
    cout << "Copy constructor called" << endl;
    Node* listCurr = list.head; // Head of original list
    Node* listCopy = head;  // Head of the copy list
    while(listCurr->next != nullptr){    //goes until the end of the list
        listCopy->next = new Node(listCurr->next->value);     //creates a new node in the copy list with the data from the curr list
        listCopy = listCopy->next;    //iterates through the two lists
        listCurr = listCurr ->next;
    }
}

LinkedList &LinkedList::operator=(const LinkedList &assignment) {     //copy assignment operator
   cout << "Copy Assignment Operator Called" << endl;

   LinkedList obj;             //creating a new object
   swap(obj.head, head);           //swaping
   return *this;
}

LinkedList::~LinkedList() {               //destructor function
    cout << "Destructor called." << endl;
    Node* curr = head;     //creating nodes to traverse the list
    Node* after = curr->next;
    while(curr->next != nullptr){      //do this until curr gets to the end of the list
        delete(curr);      //delete curr
        curr = after;   //sets curr equal to after
        after = after->next;     //iterates after one ahead of curr
    }
}

void LinkedList::append(int item) {   //this function adds new nodes onto the linked list
    if(head == nullptr){       //if there are no nodes in the list
        head = new Node(item);    //sets head equal to the new node
        size++;   //iterates size
    }
    else{       //if you are adding onto another node in the list
        Node* current = head;     //creating a node to traverse the list
        while(current->next != nullptr){     //gets current to the end of the list
            current = current->next;     //iterates current
        }
        current -> next = new Node(item);    //creating a new node at the end of the list
        size++;    //iterates size
    }
}

void LinkedList::InsertionSort() {
    Node *curr = head->next;      //creating the nodes used to traverse the linked list
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
                curr->next = head;     //sets curr's next equal to the head
                head = curr;            //sets curr's value equal to head
            } else {
                check = head;     //set check equal to head
                while (check != nullptr && check->next->value < curr->value) {   //while check dosn't reach the end of the list and checks next value is less then curr's value
                    check = check->next;   //iterate check through the list
                }
                prev->next = curr->next;     //when it reaches a value that must be swapped set prev's next equal to curr's next
                curr->next = check->next;     //set curr's next equal to check's next
                check->next = curr;              //set check's next equal to curr
            }
        }
        curr = prev->next;     //iterates curr
    }
}

void LinkedList::print() {      //print function for the linked list
    Node * cursor = head;        //creates node to traverse the list
    while ( cursor != nullptr ){    //goes until the end of the list
        cout << cursor->value << " ";    //prints the value and then a space following
        cursor = cursor -> next ;     //iterates cursor
    }
}