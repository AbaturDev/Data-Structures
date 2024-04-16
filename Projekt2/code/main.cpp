#include <iostream>
#include "priority_queue.h"
#include "priority_queue.cpp"
using namespace std;

int main()
{
    PriorityQueue<int> a;
    a.push(5, 1);
    a.display();
    return 0;
}