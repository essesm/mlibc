#ifndef LESS_H
#define LESS_H

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
