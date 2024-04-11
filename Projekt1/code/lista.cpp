#include "lista.h"

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
