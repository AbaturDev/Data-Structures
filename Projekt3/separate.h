#include "hash_table.h"

template<typename K, typename V>
struct Node
{
    K key;
    V value;
    Node *next;
};

template<typename K, typename V>
class Separate : public HashTable<K, V>
{
private:
    int size;
    int capacity;
    Node<K,V>** array;

    public:
    Separate(int size = 0, int capacity = 5);
    void display();
    void insert(K key, V value);
    int getSize();
    V find(K key);

    private:
    void rehashing();         //resize
    int hash(K key);
};

//~~~~~~~~~CODE IMPLEMENTATION~~~~~~~~~

template<typename K, typename V>
Separate<K,V>::Separate(int size, int capacity)
{
    this->capacity = capacity;
    this->size = size;
    array = new Node<K,V>*[capacity];
}

template<typename K, typename V>
int Separate<K,V>::hash(K key)
{
    return key % capacity;
}

template<typename K, typename V>
void Separate<K,V>::rehashing()
{
    capacity = capacity * 2;
    Node<K,V>** temp = new Node<K,V>*[capacity];

    for(int i = 0; i < capacity; i++)
    {
        temp[i]=array[i];
    }
    
    for(int i = 0; i < size; i++)
    {
        Node<K,V> *ptr = temp[i];
        while(ptr != nullptr)
        {
            int index = hash(ptr->key);
            if(temp[index] == nullptr)
            {
                temp[index] = ptr;
                temp[index]->next = nullptr;
            }
            else
            {
                Node<K,V> *next = temp[index]->next;
                temp[index]->next = ptr;
                ptr->next = next;
            }
            ptr = ptr->next;
        }
    }

    delete [] array;
    array = temp;
}

template<typename K, typename V>
void Separate<K,V>::insert(K key, V value)
{
    if(size==capacity)
    {
        rehashing();
    }

    size++;
    int index = hash(key);
    Node<K,V>* temp = new Node<K,V>;
    temp->key = key;
    temp->value = value;
    temp->next = nullptr;

    if(array[index]==nullptr)
    {
        array[index] = temp;
    }
    else
    {
        Node<K,V> *next = array[index]->next;
        array[index]->next = temp;
        temp->next = next;
    }
}

template<typename K, typename V>
void Separate<K,V>::display()
{
    for(int i = 0; i < capacity; i++)
    {
        Node<K,V> *temp = array[i];
        while(temp != nullptr)
        {
            cout << temp->key << ":" << temp->value << endl;
            temp = temp->next;
        }
    }
}

template<typename K, typename V>
int Separate<K,V>::getSize()
{
    return size;
}

template<typename K, typename V>
V Separate<K,V>::find(K key)
{
    int index = hash(key);
    Node<K,V> *temp = array[index];
    while(temp != nullptr)
    {
        if(temp->key == key)
        {
            return temp->value;
        }
        temp = temp->next;
    }
    cout<<"Data not found! Returing defult value"<<endl;
    return V();
}