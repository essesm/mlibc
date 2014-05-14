#include "Node.h"
#include "Pair.h"
#include "LinkedList.h"
#include "Vector.h"
#include <cassert>
#include <iostream>

using namespace std;

class Object{ };

int main()
{
	Node<int> n1(1);
	int i1 = n1.data();
	assert(i1 == 1);

	Object o1;
	Node<Object> n2(o1);

	Object *o2 = new Object();
	Node<Object> n3(*o2);

	delete o2;
	o2 = 0;

	Object *o3 = new Object();
	Node<Object*> n4(o3);
	delete o3;
	o3 = 0;

	Pair<int, double> p1;
	Pair<double, int> p2(3.14, 9);
	assert(p2.first == 3.14);
	assert(p2.second == 9);
	Pair<double, int> p3(p2);
	assert(p2.first == p3.first);
	assert(p2.second == p3.second);
	p3.first = 1.23;
	p3.second = 69;
	Pair<double, int> p4;
	p4 = p3;
	assert(p4.first == 1.23);
	assert(p4.second == 69);
	assert(p3 == p4);
	assert(p2 != p4);

	Node<bool> n5(false);
	Node<bool> n6(n5);
	Node<bool> n7;
	n7 = n5;
	n6 = n7;
	n5 = n6;

	int *i2 = new int(1);
	Node<int> n8(*i2);
	Node<int> n9(n8);
	Node<int> n10;
	n10 = n8;
	Node<int*> n11(i2);
	Node<int*> n12(n11);
	delete i2;
	i2 = 0;

	Object *o4 = new Object();
	Node<Object> n13(*o4);
	Node<Object> n14(n13);
	Node<Object> n15;
	n15 = n13;
	delete o4;
	o4 = 0;

	LinkedList<int> l;
	assert(l.size() == 0);
	assert(l.empty());
	l.push_front(1);
	assert(l.size() == 1);
	assert(!l.empty());
	assert(l.front() == 1);
	assert(l.back() == 1);
	l.push_front(2);
	assert(l.size() == 2);
	assert(!l.empty());
	assert(l.front() == 2);
	assert(l.back() == 1);
	l.push_back(3);
	assert(l.size() == 3);
	assert(!l.empty());
	assert(l.front() == 2);
	assert(l.back() == 3);
	l.pop_back();
	assert(l.size() == 2);
	assert(!l.empty());
	assert(l.front() == 2);
	assert(l.back() == 1);

	LinkedList<int> l1(l);
	assert(l == l1);
	assert(l1.size() == 2);
	assert(!l1.empty());
	l1.pop_back();
	assert(l != l1);

	Vector<int> v1;
	v1.push_back(1);
	assert(v1[0] == 1);
	assert(v1.at(0) == 1);
	assert(v1.back() == 1);
	assert(v1.size() == 1);
	assert(v1.capacity() == 1);
	assert(!v1.empty());

	v1.push_back(2);
	assert(v1[1] == 2);
	assert(v1.at(1) == 2);
	assert(v1.back() == 2);
	assert(v1.size() == 2);
	assert(v1.capacity() == 2);
	assert(!v1.empty());

	v1.push_back(3);
	assert(v1[2] == 3);
	assert(v1.at(2) == 3);
	assert(v1.back() == 3);
	assert(v1.size() == 3);
	assert(v1.capacity() == 4);
	assert(!v1.empty());

	v1.pop_back();
	assert(v1.back() == 2);
	assert(v1.size() == 2);
	assert(v1.capacity() == 4);

	Vector<int> v2(v1);
	assert(v1 == v2);
	assert(v2[0] == 1);
	assert(v2[1] == 2);
	assert(v2.size() == 2);
	assert(v2.capacity() == 4);
	assert(!v2.empty());
	v1.pop_back();
	v1.push_back(10);
	assert(v1 != v2);

	Vector<int> v3;
	v3 = v2;
	assert(v2 == v3);

	LinkedList<int> l2;
	for (int i = 0; i < 10; i++)
	{
		l2.push_back(i);
	}

	int temp  = 0;
	for (LinkedList<int>::Iterator i = l2.begin(); i != l2.end(); ++i)
	{
		assert(*i == temp++);
	}

	temp = 0;
	for (LinkedList<int>::Iterator i = l2.begin(); i != l2.end(); i++)
	{
		assert(*i == temp++);
	}

	LinkedList<int>::Iterator i = l2.end();
	while (i != l2.begin())
	{
		assert(*--i == --temp);
	}

	temp = 9;
	i = l2.end();
	i--;
	while (i != l2.begin())
	{
		assert(*i-- == temp--);
	}

	LinkedList<int> l3;
	l3.push_back(1).push_back(2).push_back(4);
	assert(l3.size() == 3);
	assert(l3.front() == 1);
	assert(l3.back() == 4);

	Vector<unsigned int> v4;
	v4.push_back(0).push_back(1).push_back(2).push_back(3);
	for (unsigned int i = 0; i < v4.size(); i++)
	{
		assert(v4.at(i) == i);
	}

	return 0;
}
