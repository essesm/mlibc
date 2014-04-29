#ifndef __PAIR_H__
#define __PAIR_H__

template <class T, class U>
class Pair
{
	public:
		Pair();
		Pair(T data1, U data2);
		Pair(const Pair<T, U> &p);
		Pair<T, U>& operator=(const Pair<T, U> &p);
		~Pair();
		T first;
		U second;

	private:
		void copy(const Pair<T, U> &p);
};

template <class T, class U>
Pair<T, U>::Pair()
{

}

template <class T, class U>
Pair<T, U>::Pair(T data1, U data2)
{
	first = data1;
	second = data2;
}

template <class T, class U>
Pair<T, U>::Pair(const Pair<T, U> &p)
{
	copy(p);
}

template <class T, class U>
Pair<T, U>& Pair<T, U>::operator=(const Pair<T, U> &p)
{
	copy(p);
	return *this;
}

template <class T, class U>
Pair<T, U>::~Pair()
{

}

template <class T, class U>
void Pair<T, U>::copy(const Pair<T, U> &p)
{
	first = p.first;
	second = p.second;
}

#endif /* __PAIR_H__ */
