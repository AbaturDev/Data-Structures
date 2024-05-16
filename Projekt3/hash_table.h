#include <iostream>
using namespace std;

template<typename K, typename V>
class HashTable
{
public:
    virtual void display() = 0;
    virtual void insert(K key, V value) = 0;
    virtual int getSize() = 0;
    virtual V find(K key) = 0; 
};