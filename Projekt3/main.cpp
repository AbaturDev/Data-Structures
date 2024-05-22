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

    a = &b;

    int count = 10;

    for(int i=0; i<count; i++)
    {
        a->insert(1,i);
    }
    //a->display();
    //cout<<a->getSize()<<endl;
    timer.find_time(*a, 2);
    //timer.insert_time(*a,count,51235);
    //timer.getSize_time(*a);
    
    return 0;
}