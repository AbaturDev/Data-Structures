#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <iostream>
using namespace std;

template <class T>
struct Node
{
    T value;
    int priority;
    Node* next;
};

template <class T>
class PriorityQueue
{
private:
    Node<T>* front;           //head
    Node<T>* rear;            //tail

public:
    PriorityQueue();
    /*
    * Constructor to set nullptr for front and rear
    */

    ~PriorityQueue();
    /*
    * Desctructor to unlock memory used by objects in PriorityQueue - clear queue
    */

    int getSize();
    /*
    * Method to get Size of queue
    * @return size of queue
    */

    void display();
    /*
    * Method to display queue
    */    
    
    //T peek();
    /*
    *
    */

    //void pop();
    /*
    *
    */

    void push(T data, int prio);
    /*
    *
    */

    //void change();
    /*
    *
    */
};

#endif