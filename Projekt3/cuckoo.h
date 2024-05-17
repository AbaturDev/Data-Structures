#ifndef CUCKOO_H
#define CUCKOO_H
#include "open_addr.h"
#include <cmath>

template<typename K, typename V>
struct CNode
{
    K key;
    V value;
};

template<typename K, typename V>
class Cuckoo : public HashTable<K,V>
{
private:
    int size;
    int capacity;
    CNode<K,V>** array1;
    CNode<K,V>** array2;

public:
    Cuckoo(int size = 0, int capacity = 5);
    void insert(K key, V value);
    V find(K key);
    void display();
    int getSize();

private:
    int hash1(K key);
    int hash2(K key);
    void rehashing();
};

//~~~~~~~~~CODE IMPLEMENTATION~~~~~~~~~

template<typename K, typename V>
Cuckoo<K,V>::Cuckoo(int size, int capacity)
{
    this->capacity = capacity;
    this->size = size;
    array1 = new CNode<K,V>*[capacity];
    array2 = new CNode<K,V>*[capacity];

    for(int i = 0; i<capacity; i++)
    {
        array1[i] = nullptr;
        array2[i] = nullptr;
    }
}

template<typename K, typename V>
int Cuckoo<K,V>::hash1(K key)
{
    double A = 0.6180339887;
    double value = key * A;
    value -= floor(value);
    return value*capacity;
}

template<typename K, typename V>
int Cuckoo<K,V>::hash2(K key)
{
    return key % capacity;
}

template<typename K, typename V>
void Cuckoo<K,V>::insert(K key, V value)
{
    float loadFactor = size/capacity;
    if(loadFactor > 0.5)
    {
        rehashing();
    }

    CNode<K,V>* newNode = new CNode<K,V>;
    newNode->key = key;
    newNode->value = value;
    int index = hash1(key);
    if(array1[index] == nullptr)
    {
        array1[index] = newNode;
        size++;
    }
    else
    {     
        CNode<K,V>* temp = array1[index];
        array1[index] = newNode;
        int newindex = hash2(key);
        while(temp != nullptr)
        {
            CNode<K,V>* temporary = temp;
            delete temp;

            index = hash2(temporary->key);
            temp = array2[index];
            if(array2[index] == nullptr)
            {
                array2[index] = temporary;
                size++;
                return;
            }

            temporary = temp;
            delete temp;

            index = hash1(temporary->key);
            temp = array1[index];
            if(array1[index] == nullptr)
            {
                array1[index] = temporary;
                size++;
                return;
            }
        }
    }
}

template<typename K, typename V>
void Cuckoo<K,V>::rehashing()
{

}

template<typename K, typename V>
void Cuckoo<K,V>::display()
{
    cout<<"~~~~Table 1~~~~"<<endl;
    for(int i = 0; i<capacity;i++)
    {
        if(array1[i] != nullptr )
        {
            cout << array1[i]->key << ":"<< array1[i]->value <<endl;
        }
    }
    cout<<"~~~~Table 2~~~~"<<endl;
    for(int i = 0; i<capacity;i++)
    {
        if(array2[i] != nullptr )
        {
            cout << array2[i]->key << ":" << array2[i]->value <<endl;
        }
    }
}

template<typename K, typename V>
int Cuckoo<K,V>::getSize()
{
    return size;
}

template<typename K, typename V>
V Cuckoo<K,V>::find(K key)
{
    int index = hash1(key);
    if(array1[index] != nullptr && array1[index]->key == key)
    {
        return array1[index]->value;
    }

    index = hash2(key);
    if(array2[index] != nullptr && array2[index]->key == key)
    {
        return array2[index]->value;
    }

    cout<<"Data not found! Returning defulat value"<<endl;
    return V();

}

#endif