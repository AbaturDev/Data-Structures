#include <iostream>
#include "separate.h"
using namespace std;

int main()
{
    Separate<int, int> a;
    a.insert(10,5);
    a.insert(2,7);
    a.insert(3,8);
    cout<<a.getSize()<<endl;
    cout<<a.find(4)<<endl;

    a.display();
    return 0;
}