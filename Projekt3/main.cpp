#include <iostream>
#include "timer.h"
using namespace std;

int main()
{   
    HashTable<int, int>* a;
    Separate<int, int> b;
    Open<int, int> c;
    Cuckoo<int, int> x;
    Timer<int, int> timer;

    a = &x;

    int count = 1000000;

    for(int i=0; i<count; i++)
    {
        a->insert(i,i);
        //a->insert(i,i+1);
    }
    cout<<a->getSize()<<endl;

    timer.find_time(*a, count-1,count-1);
    timer.insert_time(*a,count,count);
    timer.getSize_time(*a);

    //a->display();
    
    return 0;
}