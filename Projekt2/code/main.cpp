#include <iostream>
#include "priority_queue.h"
#include "priority_queue.cpp"
using namespace std;

int main()
{
    PriorityQueue<int> a;
    for(int i=1; i<6; i++)
    {
        a.push(i,i);
    }
    a.display();
    //cout<<endl<<"TEST nth"<<endl;
    //a.change(4,6);
    //a.display();

    return 0;
}

/*  
    Dziala
    cout<<endl<<"TEST front"<<endl;
    a.change(5,3);
    a.display();

    Dziala
    cout<<endl<<"TEST rear"<<endl;
    a.change(1,0);
    a.display();
*/