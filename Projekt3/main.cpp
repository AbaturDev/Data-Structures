#include <iostream>
#include "open_addr.h"
#include <chrono>
using namespace chrono;
using namespace std;

int main()
{
    Separate<int, int> a;

    for(int i=0; i<1000000; i++)
    {
        a.insert(i,i);
    }
    auto start = high_resolution_clock::now();
    a.find(100000);
    auto stop = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(stop - start);
	cout << duration.count()<<endl;
    //a.display();
    //cout<<a.find(2)<<endl;

    return 0;
}