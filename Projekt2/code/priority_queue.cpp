#include "priority_queue.h"

template <class T>
PriorityQueue<T>::PriorityQueue()
{
    front = nullptr;
    rear = nullptr;
}

template <class T>
int PriorityQueue<T>::getSize()
{
    int size = 0;
    Node<T>* temp = front;
    while(temp != nullptr)
    {
        size++;
        temp = temp->next;
    }
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
        return;
    }

    if(front->priority < temp->priority)
    {
        temp->next = front;
        front = temp;
        return;
    }
    
    if(rear->priority > temp->priority)
    {
        rear->next = temp;
        rear = temp;
        return;
    }

    Node<T> *temp2 = front;
    while(temp2->next != nullptr && temp2->priority > temp->priority)
    {
        temp2 = temp2->next;
    }

    temp->next = temp2->next;
    temp2->next = temp;
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
    return front->value;
}