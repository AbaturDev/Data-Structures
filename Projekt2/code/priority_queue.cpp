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