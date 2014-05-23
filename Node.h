#ifndef __NODE_H__ 
#define __NODE_H__

#include "Less.h"

template <class T, class C = Less<T> >
class Node
{
public:
	Node();
	Node(T data);
	Node(const Node<T, C> &n);
	Node<T, C>& operator=(const Node<T, C> &n);
	bool operator==(const Node<T, C> &n) const;
	bool operator!=(const Node<T, C> &n) const;
	bool operator<(const Node<T, C> &n) const;
	bool operator>(const Node<T, C> &n) const;
	bool operator<=(const Node<T, C> &n) const;
	bool operator>=(const Node<T, C> &n) const;
	~Node();
	const T &data() const;
	T& data();
	Node *prev;
	Node *next;
	Node *left;
	Node *right;

private:
	T *_data;
	void clear();
	void copy(const Node<T, C> &n);
	C compare;
};

template <class T, class C>
Node<T, C>::Node()
	:prev(0), next(0), left(0), right(0), _data(0)
{

}

template <class T, class C>
Node<T, C>::Node(T data)
	:prev(0), next(0), left(0), right(0)
{
	_data = new T(data);
}

template <class T, class C>
Node<T, C>::Node(const Node<T, C> &n)
{
	copy(n);
}

template <class T, class C>
Node<T, C>& Node<T, C>::operator=(const Node<T, C> &n)
{
	if (this != &n)
	{
		clear();
		copy(n);
	}

	return *this;
}

template <class T, class C>
bool Node<T, C>::operator==(const Node<T, C> &n) const
{
	if (prev != n.prev)
	{
		return false;
	}

	if (next != n.next)
	{
		return false;
	}

	if (left != n.left)
	{
		return false;
	}

	if (right != n.right)
	{
		return false;
	}

	return !(*this < n) && !(*this > n);
}

template <class T, class C>
bool Node<T, C>::operator!=(const Node<T, C> &n) const
{
	return !(*this == n);
}

template <class T, class C>
bool Node<T, C>::operator<(const Node<T, C> &n) const
{
	return compare(*this->_data, *n._data);
}

template <class T, class C>
bool Node<T, C>::operator>(const Node<T, C> &n) const
{
	return compare(*n._data, *this->_data);
}

template <class T, class C>
bool Node<T, C>::operator<=(const Node<T, C> &n) const
{
	return *this < n || *this == n;
}

template <class T, class C>
bool Node<T, C>::operator>=(const Node<T, C> &n) const
{
	return *this > n || *this == n;
}

template <class T, class C>
Node<T, C>::~Node()
{
	clear();
}

template <class T, class C>
const T& Node<T, C>::data() const
{
	return *_data;
}

template <class T, class C>
T& Node<T, C>::data()
{
	return *_data;
}

template <class T, class C>
void Node<T, C>::clear()
{
	if (_data != 0)
	{
		delete _data;
		_data = 0;
	}
}

template <class T, class C>
void Node<T, C>::copy(const Node<T, C> &n)
{
	_data = new T(*n._data);
	prev = n.prev;
	next = n.next;
	left = n.left;
	right = n.right;
}

#endif /* __NODE_H__ */
