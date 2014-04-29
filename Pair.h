#ifndef __PAIR_H__
#define __PAIR_H__

template <class T, class U>
class Pair
{
	public:
		Pair();
		Pair(T data1, U data2);
		~Pair();
		T first;
		U second;
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
Pair<T, U>::~Pair()
{

}

#endif /* __PAIR_H__ */
