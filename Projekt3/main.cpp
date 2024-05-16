#include <iostream>
#include "timer.h"
using namespace std;

int main()
{
    HashTable<int, int>* a;
    Separate<int, int> b;
    Open<int, int> c;

    a = &b;

    for(int i=0; i<1000000; i++)
    {
        a->insert(i,i);
    }

    Timer<int, int> timer;

    timer.find_time(*a, 10000);
    timer.insert_time(*a,12334,51235);
    timer.getSize_time(*a);
    
    a = &c;
    for(int i=0; i<1000000; i++)
    {
        a->insert(i,i);
    }

    timer.find_time(*a, 10000);
    timer.insert_time(*a,12334,51235);
    timer.getSize_time(*a);

    return 0;
}