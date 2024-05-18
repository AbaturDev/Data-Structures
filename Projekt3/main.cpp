#include <iostream>
#include "timer.h"
using namespace std;

int main()
{   
    HashTable<int, int>* a;
    Separate<int, int> b;
    Open<int, int> c;
    Cuckoo<int, int> x;

    a = &x;

    for(int i=0; i<13; i++)
    {
        a->insert(i,i);
    }
    a->display();
    Timer<int, int> timer;

    timer.find_time(*a, 10000);
    timer.insert_time(*a,12334,51235);
    timer.getSize_time(*a);
    
    return 0;
}