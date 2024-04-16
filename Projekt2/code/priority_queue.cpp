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
    Node<T>* temp = rear;
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
    Node<T>* temp = rear;
    
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
            cout << temp->data << " ";
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
    
    if(front == nullptr)
    {
        temp->next = front;
        front = temp;
        rear = temp;
        return;
    }

    if(front->priority < temp->priority)
    {
        temp->next = front;
        front = temp;
    }
    else
    {
        Node<T>* temp2 = front;
        while(temp2->next != nullptr && temp2->next->priority > temp->priority) 
        {
            temp2 = temp2->next;
        }

        if(temp2->next == nullptr)
        {
            rear = temp;
            return;
        }

        temp->next = temp2->next;
        temp2->next = temp;
    }
}