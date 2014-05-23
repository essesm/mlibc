#ifndef __LESS_H__
#define __LESS_H__

template <class T>
class Less
{
public:
	bool operator() (const T &x, const T &y) const;
};

template <class T>
bool Less<T>::operator()(const T &x, const T &y) const
{
	return x < y;
}

#endif /* __LESS_H__ */
