#include <iostream>
#include "priority_queue.h"
#include "priority_queue.cpp"
using namespace std;

int main()
{
    PriorityQueue<int> a;
    a.push(3, 3);
    a.push(4, 4);
    a.push(1, 1);
    a.push(2, 2);
    a.push(7, 2);
    a.display();
    return 0;
}
/*
    PriorityQueue<int> a;
    for(int i=1; i<11; i++)
    {
        a.push(i, i);
    }
    a.push(13, 5);
    a.display();
    cout<<endl<<"Peek: "<<a.peek()<<endl;
    a.display();
    cout<<endl;
    cout<<"POP: "<<a.pop()<<endl;
    a.display();
    cout<<endl;

    a.push(2, 5);
    a.push(8, 6);
    a.push(1, 4);
    a.push(5, 4);
    a.push(3, 3);
    a.push(7, 1);
    a.push(12, 6);
    a.push(3, 1);
*/