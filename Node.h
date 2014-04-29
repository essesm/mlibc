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
		T *data() const;
		Node *prev() const;
		Node *next() const;
		Node *left() const;
		Node *right() const;
	
	private:
		T *_data;
		Node *_prev;
		Node *_next;
		Node *_left;
		Node *_right;
		void clear();
		void copy(const Node<T> &n);
};

template <class T>
Node<T>::Node()
	:_data(0), _prev(0), _next(0), _left(0), _right(0)
{

}

template <class T>
Node<T>::Node(T data)
	:_prev(0), _next(0), _left(0), _right(0)
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

	if (_prev != n._prev)
	{
		return false;
	}

	if (_next != n._next)
	{
		return false;
	}

	if (_left != n._left)
	{
		return false;
	}

	if (_right != n._right)
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
T* Node<T>::data() const
{
	return _data;
}

template <class T>
Node<T>* Node<T>::prev() const
{
	return _prev;
}

template <class T>
Node<T>* Node<T>::next() const
{
	return _next;
}

template <class T>
Node<T>* Node<T>::left() const
{
	return _left;
}

template <class T>
Node<T>* Node<T>::right() const
{
	return _right;
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
	_prev = n._prev;
	_next = n._next;
	_left = n._left;
	_right = n._right;
}

#endif /* __NODE_H__ */
