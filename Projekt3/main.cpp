#include <iostream>
#include "timer.h"
using namespace std;

int main()
{   
    HashTable<int, int>* a;
    Separate<int, int> b;   //git
    Open<int, int> c;   //git
    Cuckoo<int, int> x;

    a = &b;

    for(int i=0; i<1000; i++)
    {
        a->insert(1,i);
    }
    //a->display();
    Timer<int, int> timer;

    timer.find_time(*a, 1);
    timer.insert_time(*a,1,51235);
    timer.getSize_time(*a);
    
    return 0;
}