#ifndef VECTOR_H
#define VECTOR_H

template <class T>
class Vector
{
public:
	Vector();
	Vector(const Vector<T> &v);
	Vector<T>& operator=(const Vector<T> &v);
	bool operator==(const Vector<T> &v) const;
	bool operator!=(const Vector<T> &v) const;
	~Vector();
	Vector<T>& push_back(const T &data);
	void pop_back();
	const T& front() const;
	const T& back() const;
	const T& operator[](unsigned int i) const;
	const T& at(unsigned int i) const;
	T& front();
	T& back();
	T& operator[](unsigned int i);
	T& at(unsigned int i);
	unsigned int size() const;
	unsigned int capacity() const;
	bool empty() const;
	void reserve(unsigned int capacity);

private:
	T *vector;
	void clear();
	void copy(const Vector<T> &v);
	unsigned int _size;
	unsigned int _capacity;
};

template <class T>
Vector<T>::Vector()
	:vector(0), _size(0), _capacity(1)
{
	vector = new T[_capacity];
}

template <class T>
Vector<T>::Vector(const Vector<T> &v)
	:vector(0), _size(0)
{
	copy(v);
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T> &v)
{
	if (this != &v)
	{
		clear();
		copy(v);
	}

	return *this;
}

template <class T>
bool Vector<T>::operator==(const Vector<T> &v) const
{
	if (_size != v._size)
	{
		return false;
	}

	for (unsigned int i = 0; i < _size; i++)
	{
		if (vector[i] != v.vector[i])
		{
			return false;
		}
	}

	return true;
}

template <class T>
bool Vector<T>::operator!=(const Vector<T> &v) const
{
	return !(*this == v);
}

template <class T>
Vector<T>::~Vector()
{
	clear();
}

template <class T>
Vector<T>& Vector<T>::push_back(const T &data)
{
	if (_size == _capacity)
	{
		reserve(2 * _capacity);
	}

	vector[_size++] = data;

	return *this;
}

template <class T>
void Vector<T>::pop_back()
{
	if (_size == 0)
	{
		return;
	}

	_size--;
}

template <class T>
const T& Vector<T>::front() const
{
	return vector[0];
}

template <class T>
const T& Vector<T>::back() const
{
	return vector[_size - 1];
}

template <class T>
const T& Vector<T>::operator[](unsigned int i) const
{
	return vector[i];
}

template <class T>
const T& Vector<T>::at(unsigned int i) const
{
	if (i >= _size)
	{
		throw 0;
	}

	return vector[i];
}

template <class T>
T& Vector<T>::front()
{
	return vector[0];
}

template <class T>
T& Vector<T>::back()
{
	return vector[_size - 1];
}

template <class T>
T& Vector<T>::operator[](unsigned int i)
{
	return vector[i];
}

template <class T>
T& Vector<T>::at(unsigned int i)
{
	if (i >= _size)
	{
		throw 0;
	}

	return vector[i];
}

template <class T>
unsigned int Vector<T>::size() const
{
	return _size;
}

template <class T>
unsigned int Vector<T>::capacity() const
{
	return _capacity;
}

template <class T>
bool Vector<T>::empty() const
{
	return _size == 0;
}

template <class T>
void Vector<T>::reserve(unsigned int capacity)
{
	_capacity = capacity;

	T *temp = new T[_capacity];

	for (unsigned int i = 0; i < _size; i++)
	{
		temp[i] = vector[i];
	}

	delete[] vector;
	vector = temp;
}

template <class T>
void Vector<T>::clear()
{
	delete[] vector;
	vector = 0;
	_size = 0;
}

template <class T>
void Vector<T>::copy(const Vector<T> &v)
{
	_capacity = v._capacity;
	_size = v._size;

	vector = new T[_capacity];

	for (unsigned int i = 0; i < _size; i++)
	{
		vector[i] = v.vector[i];
	}
}

#endif /* __VECTOR_H__ */
