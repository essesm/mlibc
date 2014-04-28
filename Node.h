#ifndef __NODE_H__ 
#define __NODE_H__

template <class T>
class Node
{
	public:
		Node();
		Node(T data);
		~Node();
		T *data();
		Node *prev();
		Node *next();
		Node *left();
		Node *right();
	
	private:
		T *_data;
		Node *_prev;
		Node *_next;
		Node *_left;
		Node *_right;
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
Node<T>::~Node()
{
	if (_data != 0)
	{
		delete _data;
		_data = 0;
	}
}

template <class T>
T* Node<T>::data()
{
	return _data;
}

template <class T>
Node<T>* Node<T>::prev()
{
	return _prev;
}

template <class T>
Node<T>* Node<T>::next()
{
	return _next;
}

template <class T>
Node<T>* Node<T>::left()
{
	return _left;
}

template <class T>
Node<T>* Node<T>::right()
{
	return _right;
}

#endif /* __NODE_H__ */
