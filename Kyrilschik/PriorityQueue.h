#pragma once
#include<iostream>

#include "Node.h"
#include "Stack.h"

using namespace std;

template<class T, class TPri = int>
class PriorityQueue
{
	Node<T,TPri>* first = nullptr;
	Node<T, TPri>* last = nullptr;
	size_t               size = 0;
public:
	PriorityQueue();
	PriorityQueue(initializer_list<T> list);
	PriorityQueue(const PriorityQueue& obj);
	PriorityQueue& operator=(const PriorityQueue& obj);
	~PriorityQueue();

	void enqueue(T value, TPri priority);
	void dequeue();
	T& peek();

	void clear();
	void print();

	size_t length();

};

template<class T, class TPri>
PriorityQueue<T, TPri>::PriorityQueue()
{
}

template<class T, class TPri>
PriorityQueue<T, TPri>::PriorityQueue(initializer_list<T> list)
{
}

template<class T, class TPri>
PriorityQueue<T, TPri>::PriorityQueue(const PriorityQueue& obj)
{
}

template<class T, class TPri>
PriorityQueue<T, TPri>& PriorityQueue<T, TPri>::operator=(const PriorityQueue& obj)
{
	// TODO: �������� ����� �������� return
}

template<class T, class TPri>
PriorityQueue<T, TPri>::~PriorityQueue()
{
}
/////////////////////////////////////
template<class T, class TPri>
void PriorityQueue<T, TPri>::enqueue(T value, TPri priority)
{
	Node<t, Tpri>* newNode = new Node<T, TPri>(value, priority);

	if (size == 0)
	{
		first = last = newNode;
		size++;
		return;
	}

	if (priority <= last->priority)
	{
		last->next = newNode;
		last = newNode;
	}
	else if (priority > first->priority)
	{

	}
	else
	{

	}
}
