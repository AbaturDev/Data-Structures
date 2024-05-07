#include <iostream>
#include "priority_queue.h"
#include <chrono>
using namespace chrono;
using namespace std;

int main()
{
    PriorityQueue<int> a;
    int test = 1000000;
    for(int i = 1; i < test+1; i++)
    {
        a.push(i,i);
    }

    auto start = high_resolution_clock::now();
    a.pop();
    auto stop = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(stop - start);
	cout << duration.count()<<endl;

    return 0;
}