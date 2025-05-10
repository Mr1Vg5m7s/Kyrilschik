#pragma once
#include<iostream>
#include<initializer_list>
#include<algorithm>

#include "Node.h"

using namespace std;
template<class T>
class List
{
	Node<T>* first = nullptr;
	Node<T>* last = nullptr;
	size_t   size = 0;

	Node<T>* getNode(int index);

public:
	List();
	List(initializer_list<T> list);
	List(const List& list);
	List& operator=(const List& list);
	~List();

	void push_front(T value);
	void push_back(T value);
	void insert(T value, int index);

	void pop_front();
	void pop_back();
	void remove(T index);

	T operator[](int index);

	void print();
	void clear();

};

template<class T>
inline Node<T>* List<T>::getNode(int index)
{
	Node<T>* pos;
	if (index < size / 2)
	{
		pos = first;
		for (size_t i = 0; i < index; i++)
		{
			pos = pos->next;
		}
	}
	else
	{
		pos = last;
		for (size_t i = 0; i < size - index - 1; i++)
		{
			pos = pos->prev;
		}
	}
	return pos;
}

template<class T>
List<T>::List()
{
}

template<class T>
List<T>::List(initializer_list<T> list)
{
	for (auto elem : list)
	{
		this->push_back(elem);
	}
}

template<class T>
List<T>::List(const List& list)
{
}

template<class T>
List<T>& List<T>::operator=(const List& list)
{
	// TODO: вставьте здесь оператор return
}

template<class T>
List<T>::~List()
{
	this->clear();
}

template<class T>
void List<T>::push_front(T value)
{
	if (size==0)
	{
		first = last = new Node<T>(value);
	}
	else
	{
		first->prev = new Node<T>(value);
		first->prev->next = first;
		first = first->prev;
	}
	size++;
}

template<class T>
void List<T>::push_back(T value)
{
	if (size==0)
	{
		first = last = new Node<T>(value);
	}
	else
	{
		last->next = new Node<T>(value);
		last->next->prev = last;
		last = last->next;
	}
	size++;
}

template<class T>
void List<T>::insert(T value, int index)
{
	if (index == 0)
	{
		push_front(value);
	}
	else if (index == size - 1)
	{
		push_back(value);
	}
	else
	{
		Node<T>* newNode = new Node<T>(value);
		Node<T>* pos = getNode(index-1);
		newNode->next = pos->next;
		newNode->next->prev = newNode;
		pos->next = newNode;
		newNode->prev = pos;
		size++;
	}
}

template<class T>
void List<T>::pop_front()
{
	if (size > 0)
	{
		Node<T>* pos = first;
		first = first->next;
		delete pos;
		size--;
		if (size == 0)
		{
			last = nullptr;
		}
	}
}

template<class T>
void List<T>::pop_back()
{
	if (size > 0)
	{
		if (size == 1)
		{
			delete first;
			first = last = nullptr;
			size = 0;
		}
		else
		{
			last = getNode(size - 2);
			delete last->next;
			last->next = nullptr;
		}
		size--;
	}
}

template<class T>
void List<T>::remove(T index)
{
	if (index < 0 || index >= size)
	{
		cout << "за гранью д" << endl;
	}
	else
	{
		if (index == 0)
		{
			this->pop_front();
		}
		else if (index == size - 1)
		{
			this->pop_back();
		}
		else
		{
			Node<T>* pos = getNode(index - 1);
			Node<T>* temp = pos->next;
			pos->next = pos->next->next;
			delete temp;
			size--;
		}
	}
}

template<class T>
T List<T>::operator[](int index)
{
	return T();
}

template<class T>
void List<T>::print()
{
	Node<T>* pos = first;
	while (pos)
	{
		cout << pos->value << " ";
		pos = pos->next;
	}
	cout << endl;
}

template<class T>
void List<T>::clear()
{
}
