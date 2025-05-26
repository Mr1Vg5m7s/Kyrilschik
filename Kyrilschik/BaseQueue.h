#pragma once
#include<iostream>
#include<initializer_list>

#include "Node.h"

using namespace std;

template<class T>
class BaseQueue
{
	Node<T>* first = nullptr;
	Node<T>* last = nullptr;
	size_t   size = 0;

public:
	BaseQueue();
	BaseQueue(initializer_list<T> list);
	BaseQueue(const BaseQueue& obj);
	BaseQueue& operator=(const BaseQueue& obj);
	~BaseQueue();

	void enqueue(T value);
	void dequeue();
	T& peek();

	void clear();
	void print();
	size_t length();

	void ring();
};

template<class T>
BaseQueue<T>::BaseQueue() { }

template<class T>
BaseQueue<T>::BaseQueue(initializer_list<T> list)
{
	for (auto elem : list)
	{
		this->enqueue(elem);
	}
}

template<class T>
BaseQueue<T>::BaseQueue(const BaseQueue& obj)
{
}

template<class T>
BaseQueue<T>& BaseQueue<T>::operator=(const BaseQueue& obj)
{
	// TODO:    return
}

template<class T>
BaseQueue<T>::~BaseQueue()
{
	this->clear();
}
/*
template<class T>
void BaseQueue<T>::enqueue(T value)
{
	if (size == 0)
	{
		first = last = new Node<T>(value);
	}
	else
	{
		last->next = new Node<T>(value);
		last = last->next;
	}
	size++;
}*/

template<class T>
void BaseQueue<T>::dequeue()
{
	if (size > 0)
	{
		Node<T>* temp = first;
		first = first->next;
		delete temp;
		size--;
		if (size == 0)
			last = nullptr;
	}
}

template<class T>
T& BaseQueue<T>::peek()
{
	return first->value;
}

template<class T>
void BaseQueue<T>::clear()
{
	Node<T>* temp = first;
	while (temp)
	{
		first = first->next;
		delete temp;
		temp = first;
	}
	size = 0;
	last = nullptr;
}

template<class T>
void BaseQueue<T>::print()
{
	Node<T>* temp = first;
	while (temp)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}


 /////////
template<class T>
size_t BaseQueue<T>::length()
{
	return size;
}

template<class T>
void BaseQueue<T>::ring()
{
	/*enqueue(peek());
	dequeue();*/

	last->next = first;
	first = first->next;
	last = last->next;
	last->next = nullptr;

}