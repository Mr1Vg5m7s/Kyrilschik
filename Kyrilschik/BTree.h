#pragma once

using namespace std;

#include<iostream>

template<class TKey, class TVal>
struct BTreeNode
{
	TKey key;
	TVal value;
	BTreeNode* left = nullptr;
	BTreeNode* right = nullptr;

	BTreeNode(const TKey& key, const TVal& value) : key(key), value(value){}

	void print()
	{
		if      (left != nullptr) left->print();
		cout    << value << " ";
		if      (right != nullptr) right->print();
	}

	void deleteNode()
	{
		if      (left != nullptr) left->deleteNode();
		if      (right != nullptr) right->deleteNode();
		delete  this;
	}

	TVal* getNode(const TKey& key)
	{
		if      (key == this->key) return this->value;
		else if (key < this->key && left != nullptr) left->getNode(key);
		else if (key > this->key && right != nullptr) right->getNode(key);
		else    return nullptr;
	}
};

template<class TKey, class TVal>
class BTree
{
	BTreeNode<TKey, TVal>* root = nullptr;


	BTreeNode<TKey, TVal>* push_r;
public:
	~BTree();
	void print();
	void clear();
	bool push(const TKey key,const TVal& value);
	TVal* getValue(const TKey& key);
};

template<class TKey, class TVal>
BTree<TKey, TVal>::~BTree()
{
}

template<class TKey, class TVal>
void BTree<TKey, TVal>::print()
{
	if (root)
		root->print();
	cout << endl;
}

template<class TKey, class TVal>
void BTree<TKey, TVal>::clear()
{
	if (root)
		root->deleteNode();
}

template<class TKey, class TVal>
bool BTree<TKey, TVal>::push(const TKey key, const TVal& value)
{
	if (!root)
	{
		root = new BTreeNode<TKey, TVal>(key, value);
		return true;
	}
	BTreeNode<TKey, TVal>* current = root;
	do
	{
		if (key < current->key)
		{
			if (current->left)
			{
				current = current->left;
			}
			else
			{
				current->left = new BTreeNode<TKey, TVal>(key, value);
				return true;
			}
		}
		else if (key > current->key)
		{
			if (current->right)
			{
				current = current-> right;
			}
			else
			{
				current->right = new BTreeNode<TKey, TVal>(key, value);
				return true;
			}
		}
		else
		{
			return false;
		}
	} while (true);
}

template<class TKey, class TVal>
TVal* BTree<TKey, TVal>::getValue(const TKey& key)
{
	if (root)
		root->getValue(key);
	return nullptr;
}
