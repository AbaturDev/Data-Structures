#ifndef OPEN_ADDR_H
#define OPEN_ADDR_H
#include "separate.h"
#include <cmath>

template<typename K, typename V>
struct NodeOpen
{
    K key;
    V value;
};

template<typename K, typename V>
class Open : public HashTable<K,V>
{
private:
    NodeOpen<K,V> **array;
    int size;
    int capacity;

public:
    Open(int size = 0, int capacity = 5);
    ~Open();
    void display();
    void insert(K key, V value);
    bool find(K key, V value);
    int getSize();

private:
    int hash(K key);
    void rehashing();
};

//~~~~~~~~~CODE IMPLEMENTATION~~~~~~~~~

template<typename K, typename V>
Open<K,V>::Open(int size, int capacity)
{
    this->size = size;
    this->capacity = capacity;
    array = new NodeOpen<K,V>*[capacity];

    for(int i = 0; i<capacity; i++)
    {
        array[i] = nullptr;
    }
}

template<typename K, typename V>
int Open<K,V>::hash(K key)
{
    double A = 0.6180339887;
    double value = key * A;
    value -= floor(value);
    return value*capacity;
}

template<typename K, typename V>
void Open<K,V>::insert(K key, V value)
{
    float loadFactor = size/capacity;
    if( loadFactor > 0.7 )
    {
        rehashing();
    }

    int index = hash(key);
    NodeOpen<K,V>* temp = new NodeOpen<K,V>;
    temp->key = key;
    temp->value = value;

    while(array[index] != nullptr)
    {
        index++;
        index %= capacity;
    }

    if(array[index] == nullptr)
    {
        array[index] = temp;
        size++;
    }
}

template<typename K, typename V>
void Open<K,V>::rehashing()
{
    capacity = capacity*2;
    NodeOpen<K,V>** temp = new NodeOpen<K,V>*[capacity];

    for(int i = 0; i<capacity; i++)
    {
        temp[i] = nullptr;
    }

    for(int i = 0; i<size; i++)
    {
        int index = hash(array[i]->key);

        if(temp[index] == nullptr)
        {
            temp[index] = array[i];
        }
        else
        {
            while(temp[index] != nullptr)
            {
                index++;
                index %= capacity;
            }
            
            if(temp[index] == nullptr)
            {
                temp[index] = array[i];
            }
        }
    }
    delete [] array;
    array = temp;
}

template<typename K, typename V>
int Open<K,V>::getSize()
{
    return size;
}

template<typename K, typename V>
void Open<K,V>::display()
{
    for(int i = 0; i<capacity; i++)
    {
        if(array[i] != nullptr)
        {
        cout << array[i]->key <<":"<<array[i]->value<<endl;
        }
    }
}

template<typename K, typename V>
bool Open<K,V>::find(K key, V value)
{
    int index = hash(key);
    int count = 0;
    while(array[index] != nullptr)
    {
        if(count>capacity)
        {
            cout<<"Data not found! Returning defult value"<<endl;
            return false;
        }
        if(array[index]->key == key && array[index]->value == value)
        {
            return true;
        }
        index++;
        index %= capacity;
        count++;
    }
    cout<<"Data not found! Returning defult value"<<endl;
    return false;
}

template<typename K, typename V>
Open<K,V>::~Open()
{
    for(int i = 0; i < capacity; i++)
    {
        delete array[i];
    }
    delete [] array;
}

#endif