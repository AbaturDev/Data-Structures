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
    * Desctructor to unlock memory used by objects in PriorityQueue - clear priority queue
    */

    int getSize();
    /*
    * Method to get Size of priority queue
    * @return size of priority queue
    */

    void display();
    /*
    * Method to display priority queue
    */    
    
    T peek();
    /*
    * Method to peek element with highest priority(first element)
    * @return value of element 
    */

    T pop();
    /*
    * Method to remove element with higest priority from the queue(first element)
    * @return element with highest priority
    */

    void push(T data, int prio);
    /*
    * Method to add new element to the priority queue
    * @param T data - value of element
    * @param int prio - priority of element
    */

    void change(T data, int prio);
    /*
    * Method to change priority of chosen element
    * @param T data - value of element, which priority we want to change
    * @param int prio - new priority of element
    */
};

#endif