#ifndef __GREATER_H__
#define __GREATER_H__

template <class T>
class Greater
{
public:
	bool operator() (const T &x, const T &y) const;
};

template <class T>
bool Greater<T>::operator()(const T &x, const T &y) const
{
	return x > y;
}

#endif /* __GREATER_H__ */
