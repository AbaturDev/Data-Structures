#include "open_addr.h"
#include <chrono>
using namespace chrono;

template<typename K, typename V>
class Timer
{
public:
    void insert_time(HashTable<K,V>& a, K key, V value);
    void find_time(HashTable<K,V>& a, K key);
    void getSize_time(HashTable<K,V>& a);
};

//~~~~~~~~~CODE IMPLEMENTATION~~~~~~~~~

template<typename K, typename V>
void Timer<K,V>::insert_time(HashTable<K,V>& a, K key, V value)
{
    auto start = high_resolution_clock::now();
    a.insert(key, value);
    auto stop = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(stop - start);
	cout << duration.count()<<endl;
}

template<typename K, typename V>
void Timer<K,V>::find_time(HashTable<K,V>& a, K key)
{
    auto start = high_resolution_clock::now();
    a.find(key);
    auto stop = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(stop - start);
	cout << duration.count()<<endl;
}

template<typename K, typename V>
void Timer<K,V>::getSize_time(HashTable<K,V>& a)
{
    auto start = high_resolution_clock::now();
    a.getSize();
    auto stop = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(stop - start);
	cout << duration.count()<<endl;
}