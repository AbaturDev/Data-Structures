#pragma once
#ifndef LIST_H
#define LIST_H
#include <iostream>

using namespace std;

template <class T> 
struct Node
{
	T data;				// Value of the variable
	Node* next;			// Pointer to addres of the next variable 
};

template <class T>
class LinkedList
{
private:
	Node<T>* head;		//First Node addres

public:
	LinkedList();
	/*
	* Constructor to set nullptr for head and tail
	*/

	~LinkedList();
	/*
	* Desctructor to unlock memory used by objects in LinkedList - clear linkedlist
	*/

	void add_end(T);
	/*
	* Method to add Node at the end of the list
	* @param T - value of element
	*/

	void add_begining(T);
	/*
	* Method to insert Node at the begining of the list
	* @param T - value of element
	*/

	void add_nth(T, int);
	/*
	* Method to insert Node at chosen(nth) postion of the list 
	* @param T - value of element
	* @param int -  position where we want to insert node
	*/

	void remove_begining();
	/*
	* Method to remove Node from the begining of the list
	*/

	void remove_nth(int);
	/*
	* Method to remove Node at chosen(nth) postion of the list
	* @param int -  position where we want to remove node
	*/

	void remove_end();
	/*
	* Method to remove Node from the end of the list
	*/

	void check(T);
	/*
	* Method to check if the value is element of the list
	* @param T - value of element
	*/

	void print();
	/*
	* Method to print linked list
	*/

	int get_size();
	/*
	* Method to get size of linked list
	*/

	void clear();
	/*
	* Method to clear linked list - unlock memory 
	*/
};


//-----------------Code implementation--------------------
template <class T>
LinkedList<T>::LinkedList() : head(nullptr)
{
}

template <class T>
void LinkedList<T>::add_end(T value)
{
	Node<T>* temp1 = new Node<T>;
	temp1->data = value;
	temp1->next = nullptr;

	if (head == nullptr)
	{
		temp1->next = head;
		head = temp1;
		return;
	}
	Node<T>* temp2 = head;
	while (temp2->next != nullptr)
	{
		temp2 = temp2->next;
	}
	temp2->next = temp1;
}

template <class T>
void LinkedList<T>::add_begining(T value)
{
	Node<T>* temp = new Node<T>;
	temp->data = value;
	temp->next = head;
	head = temp;
}

template <class T>
void LinkedList<T>::add_nth(T value, int position)
{
	Node<T>* temp1 = new Node<T>;
	temp1->data = value;
	temp1->next = nullptr;
	
	if (position == 1)
	{
		temp1->next = head;
		head = temp1;
		return;
	}

	Node<T>* temp2 = head;
	for (int i = 0; i < position - 2; i++)
	{
		temp2 = temp2->next;
	}
	temp1->next = temp2->next;
	temp2->next = temp1;
}

template <class T>
void LinkedList<T>::remove_begining()
{
	Node<T>* temp = head;
	head = temp->next;
	delete temp;
}

template <class T>
void LinkedList<T>::remove_end()
{
	Node<T>* temp = head;

	int size = get_size();

	if (size == 1)
	{
		head = temp->next;
		delete temp;
		return;
	}

	for (int i = 0; i < size - 2; i++)
	{
		temp = temp->next;
	}
	Node<T>* temp2 = temp->next;
	temp->next = temp2->next;
	delete temp2;
}

template <class T>
void LinkedList<T>::remove_nth(int position)
{
	Node<T>* temp = head;
	if (position == 1)
	{
		head = temp->next;
		delete temp;
		return;
	}

	for (int i = 0; i < position - 2; i++)
	{
		temp = temp->next;
	}
	Node<T>* temp2 = temp->next;
	temp->next = temp2 ->next;
	delete temp2;
}

template <class T>
void LinkedList<T>::check(T value)
{
	Node<T>* temp = head;
	while (temp != nullptr)
	{
		if (temp->data == value)
		{
			cout << "Element is part of linked list" << endl;
			return;
		}
		temp = temp->next;
	}
	cout << "Element is not part of linked list" << endl;
}

template <class T>
void LinkedList<T>::print()
{
	Node<T>* temp = head;
	cout << "~~~~LINKED LIST~~~~" << endl;
	while (temp != nullptr)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

template <class T>
int LinkedList<T>::get_size()
{
	int count = 0;
	Node<T>* temp = head;
	while (temp != nullptr)
	{
		count += 1;
		temp = temp->next;
	}
	return count;
}

template <class T>
void LinkedList<T>::clear()
{
	Node<T>* current = head;
	Node<T>* next = nullptr;

	while (current != nullptr)
	{
		next = current->next;
		delete current;
		current = next;
	}
	head = nullptr;
}

template <class T>
LinkedList<T>::~LinkedList() 
{
	clear();
}


#endif