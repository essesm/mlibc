#ifndef __NODE_H__ 
#define __NODE_H__

template <class T>
class Node
{
public:
	Node();
	Node(T data);
	Node(const Node<T> &n);
	Node<T>& operator=(const Node<T> &n);
	bool operator==(const Node<T> &n) const;
	bool operator!=(const Node<T> &n) const;
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
	void copy(const Node<T> &n);
};

template <class T>
Node<T>::Node()
	:prev(0), next(0), left(0), right(0), _data(0)
{

}

template <class T>
Node<T>::Node(T data)
	:prev(0), next(0), left(0), right(0)
{
	_data = new T(data);
}

template <class T>
Node<T>::Node(const Node<T> &n)
{
	copy(n);
}

template <class T>
Node<T>& Node<T>::operator=(const Node<T> &n)
{
	if (this != &n)
	{
		clear();
		copy(n);
	}

	return *this;
}

template <class T>
bool Node<T>::operator==(const Node<T> &n) const
{
	if (*_data != *n._data)
	{
		return false;
	}

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

	return true;
}

template <class T>
bool Node<T>::operator!=(const Node<T> &n) const
{
	return !(*this == n);
}

template <class T>
Node<T>::~Node()
{
	clear();
}

template <class T>
const T& Node<T>::data() const
{
	return *_data;
}

template <class T>
T& Node<T>::data()
{
	return *_data;
}

template <class T>
void Node<T>::clear()
{
	if (_data != 0)
	{
		delete _data;
		_data = 0;
	}
}

template <class T>
void Node<T>::copy(const Node<T> &n)
{
	_data = new T(*n._data);
	prev = n.prev;
	next = n.next;
	left = n.left;
	right = n.right;
}

#endif /* __NODE_H__ */
