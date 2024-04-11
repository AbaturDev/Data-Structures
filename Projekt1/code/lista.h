#pragma once
#ifndef LISTA_H
#define LISTA_H
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
#endif