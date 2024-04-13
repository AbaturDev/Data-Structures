#include <iostream>
#include <cstdlib>
#include <ctime>
#include "lista.h"
#include "lista.cpp"
#include <chrono>
using namespace chrono;
using namespace std;

int main()
{
	srand (time(nullptr));

	LinkedList<int> a;
	for(int i=0; i<100000; i++)
	{
		int random = rand() % 101;
		a.add_begining(random);
	}
	auto start = high_resolution_clock::now();
	a.add_end(5);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(stop - start);
	cout << duration.count()<<endl;
	return 0;
}
