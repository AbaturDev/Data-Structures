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
    void resize();
    int new_hash1(K key);
    int new_hash2(K key);
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
        int newindex = hash2(array1[index]->key);
        if(array2[newindex] == nullptr)
        {
            array2[newindex] = array1[index];
            array1[index] = newNode;
            size++;
        }
        else
        {
            int index3 = hash1(array2[newindex]->key);
            if(array1[index] == nullptr)
            {
                array1[index3] = array2[newindex];
                array2[newindex] = array1[index];
                array1[index] = newNode;
                size++;
                return;
            }
            rehashing();
            insert(key, value);
        }
    }
}

template<typename K, typename V>
void Cuckoo<K,V>::rehashing()
{
    int oldCap = capacity;
    capacity = capacity*2;
    CNode<K,V>** temp_arr1 = array1;
    CNode<K,V>** temp_arr2 = array2;

    array1 = new CNode<K,V>*[capacity];
    array2 = new CNode<K,V>*[capacity];
    
    for(int i = 0; i < capacity; i++)
    {
        array1[i] = nullptr;
        array2[i] = nullptr;
    }

    size = 0;

    for(int i = 0; i<oldCap; i++)
    {
        if(temp_arr1[i] != nullptr)
        {
            insert(temp_arr1[i]->key, temp_arr1[i]->value);
        }

        if(temp_arr2[i] != nullptr)
        {
            insert(temp_arr2[i]->key, temp_arr2[i]->value);
        }
    }
    delete [] temp_arr1;
    delete [] temp_arr2;
}

/*
template<typename K, typename V>
void Cuckoo<K,V>::rehashing()
{
    // Przechowywanie starych tablic
    CNode<K,V>** oldArray1 = array1;
    CNode<K,V>** oldArray2 = array2;

    // Tworzenie nowych tablic
    array1 = new CNode<K,V>*[capacity];
    array2 = new CNode<K,V>*[capacity];

    for(int i = 0; i < capacity; i++)
    {
        array1[i] = nullptr;
        array2[i] = nullptr;
    }

    // Przenoszenie elementów ze starej tablicy array1
    for(int i = 0; i < size; i++)
    {
        if (oldArray1[i] != nullptr)
        {
            int index1 = new_hash1(oldArray1[i]->key);
            if (array1[index1] == nullptr)
            {
                array1[index1] = oldArray1[i];
            }
            else
            {
                CNode<K,V>* displacedNode = array1[index1];
                array1[index1] = oldArray1[i];
                
                int index2 = new_hash2(displacedNode->key);
                if (array2[index2] == nullptr)
                {
                    array2[index2] = displacedNode;
                }
                else
                {
                    // Jeśli już jest element w array2, przesuwamy go z powrotem do array1
                    array1[new_hash1(displacedNode->key)] = displacedNode;
                }
            }
        }
    }

    // Przenoszenie elementów ze starej tablicy array2
    for(int i = 0; i < size; i++)
    {
        if (oldArray2[i] != nullptr)
        {
            int index1 = new_hash1(oldArray2[i]->key);
            if (array1[index1] == nullptr)
            {
                array1[index1] = oldArray2[i];
            }
            else
            {
                CNode<K,V>* displacedNode = array1[index1];
                array1[index1] = oldArray2[i];
                
                int index2 = new_hash2(displacedNode->key);
                if (array2[index2] == nullptr)
                {
                    array2[index2] = displacedNode;
                }
                else
                {
                    // Jeśli już jest element w array2, przesuwamy go z powrotem do array1
                    array1[new_hash1(displacedNode->key)] = displacedNode;
                }
            }
        }
    }

    // Zwolnienie pamięci
    delete[] oldArray1;
    delete[] oldArray2;
}

//moj
/*
template<typename K, typename V>
void Cuckoo<K,V>::rehashing()
{
    CNode<K,V>** temp_arr1 = new CNode<K,V>*[capacity];
    CNode<K,V>** temp_arr2 = new CNode<K,V>*[capacity];

    for(int i = 0; i < capacity; i++)
    {
        temp_arr1[i] = nullptr;
        temp_arr2[i] = nullptr;
    }
    
    for(int i = 0; i < size; i++)
    {
        int index = new_hash1(array1[i]->key);
        if(temp_arr1[index] == nullptr )
        {
            temp_arr1[i] = array1[i];
        }
        else
        {
            int newindex = new_hash2(temp_arr1[index]->key);
            if(temp_arr2[newindex] == nullptr)
            {
                temp_arr2[newindex] = temp_arr1[index]; 
                temp_arr1[index] = array1[i];
            }
            else
            {
                int index3 = new_hash1(temp_arr2[newindex]->key);
                if(temp_arr1[index3] == nullptr)
                {
                    temp_arr1[index3] = temp_arr2[newindex];
                    temp_arr2[newindex] = temp_arr1[index]; 
                    temp_arr1[index] = array1[i];
                }
            }           
        }

        index = new_hash2(array2[i]->key);
        if(temp_arr2[index] == nullptr )
        {
            temp_arr2[i] = array1[i];
        }
        else
        {
            int newindex = new_hash1(temp_arr2[index]->key);
            if(temp_arr1[newindex] == nullptr)
            {
                temp_arr1[newindex] = temp_arr2[index]; 
                temp_arr2[index] = array2[i];
            }
            else
            {
                int index3 = new_hash2(temp_arr1[newindex]->key);
                if(temp_arr2[index3] == nullptr)
                {
                    temp_arr2[index3] = temp_arr1[newindex];
                    temp_arr1[newindex] = temp_arr2[index]; 
                    temp_arr2[index] = array2[i];
                }
            }           
        }

    }

    delete [] array1;
    delete [] array2;
    array1 = temp_arr1;
    array2 = temp_arr2;
}*/

template<typename K, typename V>
int Cuckoo<K,V>::new_hash1(K key)
{
    double A = 0.70710678118; 
    double value = key * A;
    value -= floor(value);
    return value * capacity;
}

template<typename K, typename V>
int Cuckoo<K,V>::new_hash2(K key)
{
    return (key/capacity) % capacity;
}

template<typename K, typename V>
void Cuckoo<K,V>::resize()
{
    capacity = capacity * 2;
    rehashing();
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
    int newindex = new_hash1(key);
    if(array1[index] != nullptr && array1[index]->key == key)
    {
        return array1[index]->value;
    }

    if(array1[newindex] != nullptr && array1[newindex]->key == key)
    {
        return array1[newindex]->value;
    }

    index = hash2(key);
    newindex = new_hash2(key);
    if(array2[index] != nullptr && array2[index]->key == key)
    {
        return array2[index]->value;
    }

    if(array2[newindex] != nullptr && array2[newindex]->key == key)
    {
        return array2[newindex]->value;
    }

    cout<<"Data not found! Returning defulat value"<<endl;
    return V();

}

#endif