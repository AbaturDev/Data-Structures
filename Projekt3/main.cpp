#include <iostream>
#include "separate.h"
using namespace std;

int main()
{
    Separate<int, int> a;
    for(int i=0; i<10; i++)
    {
        a.insert(i,i);
    }
    a.insert(9,10);
    a.insert(9,11);
    a.insert(5,6);

    a.display();
    return 0;
}