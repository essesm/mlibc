#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Node.h"

template <class T>
class LinkedList
{
public:
	LinkedList();
	LinkedList(const LinkedList<T> &l);
	LinkedList<T>& operator=(const LinkedList<T> &l);
	bool operator==(const LinkedList<T> &l) const;
	bool operator!=(const LinkedList<T> &l) const;
	~LinkedList();
	LinkedList<T>& push_front(const T &data);
	LinkedList<T>& push_back(const T &data);
	void pop_front();
	void pop_back();
	const T& front() const;
	const T& back() const;
//	T& front();
//	T& back();
	unsigned int size() const;
	bool empty() const;

	class Iterator
	{
	public:
		Iterator();
		Iterator(const Iterator &i);
		bool operator==(const Iterator &i) const;
		bool operator!=(const Iterator &i) const;
		T& operator*() const;
		Iterator& operator++();
		Iterator& operator--();
		Iterator operator++(int);
		Iterator operator--(int);
		~Iterator();

	private:
		Iterator(Node<T> *head, Node<T> *tail, Node<T> *n);
		Node<T> *head;
		Node<T> *tail;
		Node<T> *node;
		friend class LinkedList;
	};

	Iterator begin();
	Iterator end();

private:
	Node<T> *head;
	Node<T> *tail;
	void clear();
	void copy(const LinkedList<T> &l);
	unsigned int _size;
};

template <class T>
LinkedList<T>::LinkedList()
	:head(0), tail(0), _size(0)
{

}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &l)
	:head(0), tail(0), _size(0)
{
	copy(l);
}

template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T> &l)
{
	if (this != &l)
	{
		clear();
		copy(l);
	}

	return *this;
}

template <class T>
bool LinkedList<T>::operator==(const LinkedList<T> &l) const
{
	Node<T> *n1 = head;
	Node<T> *n2 = l.head;

	while (n1 != 0 && n2 != 0)
	{
		if (n1->data() != n2->data())
		{
			return false;
		}

		n1 = n1->next;
		n2 = n2->next;
	}

	if (n1 == 0 && n2 == 0)
	{
		return true;
	}

	return false;
}

template <class T>
bool LinkedList<T>::operator!=(const LinkedList<T> &l) const
{
	return !(*this == l);
}

template <class T>
LinkedList<T>::~LinkedList()
{
	clear();
}

template <class T>
LinkedList<T>& LinkedList<T>::push_front(const T &data)
{
	Node<T> *temp = new Node<T>(data);

	if (head != 0)
	{
		head->prev = temp;
	}
	else
	{
		tail = temp;
	}

	temp->next = head;
	head = temp;

	_size++;

	return *this;
}

template <class T>
LinkedList<T>& LinkedList<T>::push_back(const T &data)
{
	Node<T> *temp = new Node<T>(data);

	if (tail != 0)
	{
		tail->next = temp;
	}
	else
	{
		head = temp;
	}

	temp->prev = tail;
	tail = temp;

	_size++;

	return *this;
}

template <class T>
void LinkedList<T>::pop_front()
{
	if (head == 0)
	{
		return;
	}

	Node<T> *temp = head;
	head = head->next;

	if (head != 0)
	{
		head->prev = 0;
	}

	delete temp;
	temp = 0;

	_size--;
}

template <class T>
void LinkedList<T>::pop_back()
{
	if (tail == 0)
	{
		return;
	}

	Node<T> *temp = tail;
	tail = tail->prev;

	if (tail != 0)
	{
		tail->next = 0;
	}

	delete temp;
	temp = 0;

	_size--;
}

template <class T>
const T& LinkedList<T>::front() const
{
	return head->data();
}

template <class T>
const T& LinkedList<T>::back() const
{
	return tail->data();
}

// template <class T>
// T& LinkedList<T>::front()
// {
// 	return head->data();
// }
//
// template <class T>
// T& LinkedList<T>::back()
// {
// 	return tail->data();
// }

template <class T>
void LinkedList<T>::clear()
{
	while (head != 0)
	{
		pop_front();
	}
}

template <class T>
void LinkedList<T>::copy(const LinkedList<T> &l)
{
	Node<T> *temp = l.head;
	while (temp != 0)
	{
		push_back(temp->data());
		temp = temp->next;
	}
}

template <class T>
unsigned int LinkedList<T>::size() const
{
	return _size;
}

template <class T>
bool LinkedList<T>::empty() const
{
	return _size == 0;
}

template <class T>
LinkedList<T>::Iterator::Iterator()
	:head(0), tail(0), node(0)
{

}

template <class T>
LinkedList<T>::Iterator::Iterator(const Iterator &i)
	:head(i.head), tail(i.tail), node(i.node)
{

}

template <class T>
LinkedList<T>::Iterator::Iterator(Node<T> *head, Node<T> *tail, Node<T> *n)
	:head(head), tail(tail), node(n)
{

}

template <class T>
bool LinkedList<T>::Iterator::operator==(const Iterator &i) const
{
	return node == i.node;
}

template <class T>
bool LinkedList<T>::Iterator::operator!=(const Iterator &i) const
{
	return !(*this == i);
}

template <class T>
T& LinkedList<T>::Iterator::operator*() const
{
	return node->data();
}

template <class T>
typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator++()
{
	if (node != 0)
	{
		node = node->next;
	}
	else
	{
		node = head;
	}

	return *this;
}

template <class T>
typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator--()
{
	if (node != 0)
	{
		node = node->prev;
	}
	else
	{
		node = tail;
	}

	return *this;
}

template <class T>
typename LinkedList<T>::Iterator LinkedList<T>::Iterator::operator++(int)
{
	Iterator i(*this);
	++*this;

	return i;
}

template <class T>
typename LinkedList<T>::Iterator LinkedList<T>::Iterator::operator--(int)
{
	Iterator i(*this);
	--*this;

	return i;
}

template <class T>
LinkedList<T>::Iterator::~Iterator()
{

}

template <class T>
typename LinkedList<T>::Iterator LinkedList<T>::begin()
{
	return Iterator(head, tail, head);
}

template <class T>
typename LinkedList<T>::Iterator LinkedList<T>::end()
{
	return Iterator(head, tail, 0);
}

#endif /* LINKED_LIST_H */
