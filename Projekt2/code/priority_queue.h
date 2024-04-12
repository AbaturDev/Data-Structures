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
    ~PriorityQueue();
    int getSize();
    void display();
    T peek();
    void pop();
    void push(T value, int priority);
    //void change();
};

#endif