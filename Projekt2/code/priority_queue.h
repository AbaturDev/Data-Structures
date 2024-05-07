#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <iostream>
#include <stdexcept>
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
    int size;
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


//--------------Code implementation--------------------

template <class T>
PriorityQueue<T>::PriorityQueue()
{
    front = nullptr;
    rear = nullptr;
    size = 0;
}

template <class T>
int PriorityQueue<T>::getSize()
{
    return size;
}

template <class T>
void PriorityQueue<T>::display()
{
    Node<T>* temp = front;
    
    cout << "~~~~QUEUE~~~~" << endl;
    
    if(getSize()==0)
    {
        cout<<"Queue is empty"<<endl;
        return;
    }
    else
    {
        while(temp != nullptr)
        {
            cout << temp->value << " ";
            temp =  temp->next;
        }
        cout<<endl;
    }
}

template <class T>
void PriorityQueue<T>::push(T data, int prio)
{ 
    Node<T>* temp = new Node<T>;
    temp->value = data;
    temp->priority = prio;
    temp->next = nullptr;

    if(front == nullptr && rear == nullptr)
    {
        front = temp;
        rear = temp;
        size++;
        return;
    }

    if(front->priority < temp->priority)
    {
        temp->next = front;
        front = temp;
        size++;
        return;
    }
    
    if(rear->priority >= temp->priority)
    {
        rear->next = temp;
        rear = temp;
        size++;
        return;
    }

    Node<T> *temp2 = front;
    while(temp2->next != nullptr && temp2->next->priority >= temp->priority)
    {
        temp2 = temp2->next;
    }

    temp->next = temp2->next;
    temp2->next = temp;
    size++;
}

template <class T>
PriorityQueue<T>::~PriorityQueue()
{
    Node<T>* temp = front;
    Node<T>* next = nullptr;
    while(temp != nullptr)
    {
        next = temp->next;
        delete temp;
        temp = next;
    }
    front = nullptr;
    rear = nullptr;
}

template <class T>
T PriorityQueue<T>::peek()
{
    if(front == nullptr)
    {
        throw runtime_error("Queue is empty");
    }

    return front->value;
}

template <class T>
T PriorityQueue<T>::pop()
{
    if(front == nullptr)
    {
        throw runtime_error("Queue is empty");
    }

    Node<T>* temp = front;
    front = temp->next;
    T tempVal = temp->value;
    delete temp;
    return tempVal;
}

template <class T>
void PriorityQueue<T>::change(T data, int prio)
{
    if(front==nullptr)
    {
        return;
    }

    Node<T>* temp = front;
    if(front->value == data)
    {
        front = temp->next;
        delete temp;
        push(data, prio);
    }
    else if(rear->value == data)
    {
        for(int i=0; i<getSize()-2; i++)
        {
            temp=temp->next;
        }
        Node<T>* temp2 = temp->next;
        temp->next = temp2->next;
        rear = temp;
        temp->next = nullptr;
        delete temp2;
        push(data, prio);
    }
    else
    {
        int position = 1;
        while(temp != nullptr && temp->value != data)
        {
            temp=temp->next;
            position++;
        }
        if(temp == nullptr)
        {
            return;
        }
        
        temp=front;
        for(int i=0; i<position-2; i++)
        {
            temp=temp->next;
        }
        Node<T>* temp2 = temp->next;
        temp->next = temp2->next;
        delete temp2;   
        push(data, prio);
    }
}

#endif