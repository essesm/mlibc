#include "Node.h"
#include "Pair.h"
#include "LinkedList.h"
#include "Vector.h"
#include "Less.h"
#include "Greater.h"
#include <cassert>
#include <iostream>
#include <functional>

using namespace std;

class Object
{ 
public:
	int x;
};

class ObjectCompare
{
public:
	bool operator()(const Object &x, const Object &y) const
	{
		return x.x < y.x;
	}
};

// class Comparable
// {
// public:
// 	Comparable():x(0) { }
// 	int x;
// };
// 
// class FunctionObject
// {
// public:
// 	bool operator()(const Comparable &x, const Comparable &y) const
// 	{
// 		return x.x < y.x;
// 	}
// };

int main()
{
	/* LESS.H TEST */
	{
		Less<int> intComp;
		assert(intComp(1, 2));
		assert(!intComp(2, 1));
		assert(!intComp(1, 1));

		Less<double> doubleComp;
		assert(doubleComp(1.2, 1.21));
		assert(!doubleComp(1.21, 1.2));
		assert(!doubleComp(1.21, 1.21));

		Less<int> *intCompPtr = new Less<int>();
		assert((*intCompPtr)(1, 2));
		assert(!(*intCompPtr)(2, 1));
		assert(!(*intCompPtr)(1, 1));
		delete intCompPtr;
		intCompPtr = 0;

		Less<double> *doubleCompPtr = new Less<double>();
		assert((*doubleCompPtr)(1.2, 1.21));
		assert(!(*doubleCompPtr)(1.21, 1.2));
		assert(!(*doubleCompPtr)(1.21, 1.21));
		delete doubleCompPtr;
		doubleCompPtr = 0;
	}

	/* GREATER.H TEST */
	{
		Greater<int> intComp;
		assert(intComp(2, 1));
		assert(!intComp(1, 2));
		assert(!intComp(1, 1));

		Greater<double> doubleComp;
		assert(doubleComp(1.21, 1.2));
		assert(!doubleComp(1.2, 1.21));
		assert(!doubleComp(1.21, 1.21));

		Greater<int> *intCompPtr = new Greater<int>();
		assert((*intCompPtr)(2, 1));
		assert(!(*intCompPtr)(1, 2));
		assert(!(*intCompPtr)(1, 1));
		delete intCompPtr;
		intCompPtr = 0;

		Greater<double> *doubleCompPtr = new Greater<double>();
		assert((*doubleCompPtr)(1.21, 1.2));
		assert(!(*doubleCompPtr)(1.2, 1.21));
		assert(!(*doubleCompPtr)(1.21, 1.21));
		delete doubleCompPtr;
		doubleCompPtr = 0;
	}

	/* NODE.H INT TEST */
	{
		Node<int> n1(1);
		assert(n1.data() == 1);
		assert(n1.prev == 0);
		assert(n1.next == 0);
		assert(n1.left == 0);
		assert(n1.right == 0);
		n1.data() = 2;			// Change node data
		assert(n1.data() == 2);
		assert(n1.prev == 0);
		assert(n1.next == 0);
		assert(n1.left == 0);
		assert(n1.right == 0);

		Node<int> n2(2);
		assert(n2.data() == 2);
		assert(n2.prev == 0);
		assert(n2.next == 0);
		assert(n2.left == 0);
		assert(n2.right == 0);

		// Comparison operators with n1 == n2
		assert(n1 == n2);
		assert(!(n1 != n2));
		assert(n1 <= n2);
		assert(n1 >= n2);
		assert(!(n1 < n2));
		assert(!(n1 > n2));
		assert(n2 == n1);
		assert(!(n2 != n1));
		assert(n2 <= n1);
		assert(n2 >= n1);
		assert(!(n2 < n1));
		assert(!(n2 > n1));

		n1.data() = 1;		// Change node data
		assert(n1.data() == 1);
		assert(n1.prev == 0);
		assert(n1.next == 0);
		assert(n1.left == 0);
		assert(n1.right == 0);

		assert(n2.data() == 2);
		assert(n2.prev == 0);
		assert(n2.next == 0);
		assert(n2.left == 0);
		assert(n2.right == 0);

		// Comparison operator with n1 < n2
		assert(!(n1 == n2));
		assert(n1 != n2);
		assert(n1 <= n2);
		assert(!(n1 >= n2));
		assert(n1 < n2);
		assert(!(n1 > n2));
		assert(!(n2 == n1));
		assert((n2 != n1));
		assert(!(n2 <= n1));
		assert(n2 >= n1);
		assert(!(n2 < n1));
		assert((n2 > n1));
	}

	/* NODE.H INT* TEST */
	{
		int *i1 = new int(1);
		int *i2 = new int(2);
		Node<int*> n1(i1);
		assert(*n1.data() == 1);
		assert(n1.prev == 0);
		assert(n1.next == 0);
		assert(n1.left == 0);
		assert(n1.right == 0);
		*n1.data() = *i2;		// Change node data
		assert(*n1.data() == 2);
		assert(n1.prev == 0);
		assert(n1.next == 0);
		assert(n1.left == 0);
		assert(n1.right == 0);

		Node<int*> n2(i2);
		assert(*n2.data() == 2);
		assert(n2.prev == 0);
		assert(n2.next == 0);
		assert(n2.left == 0);
		assert(n2.right == 0);

		// Equality operators with n1 containing a different address than n2
		// Comparison operators hold no meaning
		assert(*n1.data() == *n2.data());
		assert(!(n1 == n2));
		assert(n1 != n2);

		delete i1;
		delete i2;
		i1 = 0;
		i2 = 0;
	}

	/* NODE.H INT AND INT* TEST */
	{
		int *i1 = new int(1);
		int *i2 = new int(2);
		Node<int> n1(*i1);
		assert(n1.data() == 1);
		assert(n1.prev == 0);
		assert(n1.next == 0);
		assert(n1.left == 0);
		assert(n1.right == 0);
		n1.data() = *i2;		// Change node data
		assert(n1.data() == 2);
		assert(n1.prev == 0);
		assert(n1.next == 0);
		assert(n1.left == 0);
		assert(n1.right == 0);
		n1.data() = 3;			// Change node data
		assert(n1.data() == 3);
		assert(n1.prev == 0);
		assert(n1.next == 0);
		assert(n1.left == 0);
		assert(n1.right == 0);

		delete i1;
		delete i2;
		i1 = 0;
		i2 = 0;
	}

	/* DYNAMIC NODE.H INT TEST */
	{
		Node<int> *n1 = new Node<int>(1);
		assert(n1->data() == 1);
		assert(n1->prev == 0);
		assert(n1->next == 0);
		assert(n1->left == 0);
		assert(n1->right == 0);
		n1->data() = 2;			// Change node data
		assert(n1->data() == 2);
		assert(n1->prev == 0);
		assert(n1->next == 0);
		assert(n1->left == 0);
		assert(n1->right == 0);

		Node<int> *n2 = new Node<int>(2);
		assert(n2->data() == 2);
		assert(n2->prev == 0);
		assert(n2->next == 0);
		assert(n2->left == 0);
		assert(n2->right == 0);

		// Comparison operators with n1 == n2
		assert(*n1 == *n2);
		assert(!(*n1 != *n2));
		assert(*n1 <= *n2);
		assert(*n1 >= *n2);
		assert(!(*n1 < *n2));
		assert(!(*n1 > *n2));
		assert(*n2 == *n1);
		assert(!(*n2 != *n1));
		assert(*n2 <= *n1);
		assert(*n2 >= *n1);
		assert(!(*n2 < *n1));
		assert(!(*n2 > *n1));

		n1->data() = 1;		// Change node data
		assert(n1->data() == 1);
		assert(n1->prev == 0);
		assert(n1->next == 0);
		assert(n1->left == 0);
		assert(n1->right == 0);

		assert(n2->data() == 2);
		assert(n2->prev == 0);
		assert(n2->next == 0);
		assert(n2->left == 0);
		assert(n2->right == 0);

		// Comparison operator with n1 < n2
		assert(!(*n1 == *n2));
		assert(*n1 != *n2);
		assert(*n1 <= *n2);
		assert(!(*n1 >= *n2));
		assert(*n1 < *n2);
		assert(!(*n1 > *n2));
		assert(!(*n2 == *n1));
		assert((*n2 != *n1));
		assert(!(*n2 <= *n1));
		assert(*n2 >= *n1);
		assert(!(*n2 < *n1));
		assert((*n2 > *n1));

		delete n1;
		delete n2;
		n1 = 0;
		n2 = 0;
	}

	/* DYNAMIC NODE.H INT* TEST */
	{
		int *i1 = new int(1);
		int *i2 = new int(2);
		Node<int*> *n1 = new Node<int*>(i1);
		assert(*n1->data() == 1);
		assert(n1->prev == 0);
		assert(n1->next == 0);
		assert(n1->left == 0);
		assert(n1->right == 0);
		*n1->data() = *i2;		// Change node data
		assert(*n1->data() == 2);
		assert(n1->prev == 0);
		assert(n1->next == 0);
		assert(n1->left == 0);
		assert(n1->right == 0);

		Node<int*> *n2 = new Node<int*>(i2);
		assert(*n2->data() == 2);
		assert(n2->prev == 0);
		assert(n2->next == 0);
		assert(n2->left == 0);
		assert(n2->right == 0);

		// Equality operators with n1 containing a different address than n2
		// Comparison operators hold no meaning
		assert(*n1->data() == *n2->data());
		assert(!(*n1 == *n2));
		assert(*n1 != *n2);

		delete i1;
		delete i2;
		delete n1;
		delete n2;
		i1 = 0;
		i2 = 0;
		n1 = 0;
		n2 = 0;
	}

	/* NODE.H OBJECT TEST */
	{
		Object o1;
		o1.x = 1;
		Node<Object, ObjectCompare> n1(o1);
		assert(n1.data().x == o1.x);
		assert(n1.data().x == 1);
		assert(n1.prev == 0);
		assert(n1.next == 0);
		assert(n1.left == 0);
		assert(n1.right == 0);
		n1.data().x = 2;			// Change node data
		assert(n1.data().x == 2);
		assert(n1.prev == 0);
		assert(n1.next == 0);
		assert(n1.left == 0);
		assert(n1.right == 0);

		Object o2;
		o2.x = 2;
		Node<Object, ObjectCompare> n2(o2);
		assert(n2.data().x == o2.x);
		assert(n2.data().x == 2);
		assert(n2.prev == 0);
		assert(n2.next == 0);
		assert(n2.left == 0);
		assert(n2.right == 0);

		// Comparison operators with n1 == n2
		assert(n1 == n2);
		assert(!(n1 != n2));
		assert(n1 <= n2);
		assert(n1 >= n2);
		assert(!(n1 < n2));
		assert(!(n1 > n2));
		assert(n2 == n1);
		assert(!(n2 != n1));
		assert(n2 <= n1);
		assert(n2 >= n1);
		assert(!(n2 < n1));
		assert(!(n2 > n1));

		n1.data().x = 1;		// Change node data
		assert(n1.data().x == o1.x);
		assert(n1.data().x == 1);
		assert(n1.prev == 0);
		assert(n1.next == 0);
		assert(n1.left == 0);
		assert(n1.right == 0);

		assert(n2.data().x == o2.x);
		assert(n2.data().x == 2);
		assert(n2.prev == 0);
		assert(n2.next == 0);
		assert(n2.left == 0);
		assert(n2.right == 0);

		// Comparison operator with n1 < n2
		assert(!(n1 == n2));
		assert(n1 != n2);
		assert(n1 <= n2);
		assert(!(n1 >= n2));
		assert(n1 < n2);
		assert(!(n1 > n2));
		assert(!(n2 == n1));
		assert((n2 != n1));
		assert(!(n2 <= n1));
		assert(n2 >= n1);
		assert(!(n2 < n1));
		assert((n2 > n1));
	}

	/* NODE.H OBJECT* TEST */
	{
		Object *o1 = new Object();
		Object *o2 = new Object();
		o1->x = 1;
		o2->x = 2;
		Node<Object*> n1(o1);
		assert(n1.data()->x == o1->x);
		assert(n1.data()->x == 1);
		assert(n1.prev == 0);
		assert(n1.next == 0);
		assert(n1.left == 0);
		assert(n1.right == 0);
		*n1.data() = *o2;		// Change node data
		assert(n1.data()->x == o2->x);
		assert(n1.data()->x == 2);
		assert(n1.prev == 0);
		assert(n1.next == 0);
		assert(n1.left == 0);
		assert(n1.right == 0);

		Node<Object*> n2(o2);
		assert(n2.data()->x == 2);
		assert(n2.prev == 0);
		assert(n2.next == 0);
		assert(n2.left == 0);
		assert(n2.right == 0);

		// Equality operators with n1 containing a different address than n2
		// Comparison operators hold no meaning
		assert(n1.data()->x == n2.data()->x);
		assert(!(n1 == n2));
		assert(n1 != n2);

		delete o1;
		delete o2;
		o1 = 0;
		o2 = 0;
	}


//	Node<int> n1(1);
//	int i1 = n1.data();
//	assert(i1 == 1);
//
//	Object o1;
//	Node<Object> n2(o1);
//
//	Object *o2 = new Object();
//	Node<Object> n3(*o2);
//
//	delete o2;
//	o2 = 0;
//
//	Object *o3 = new Object();
//	Node<Object*> n4(o3);
//	delete o3;
//	o3 = 0;
//
//	Pair<int, double> p1;
//	Pair<double, int> p2(3.14, 9);
//	assert(p2.first == 3.14);
//	assert(p2.second == 9);
//	Pair<double, int> p3(p2);
//	assert(p2.first == p3.first);
//	assert(p2.second == p3.second);
//	p3.first = 1.23;
//	p3.second = 69;
//	Pair<double, int> p4;
//	p4 = p3;
//	assert(p4.first == 1.23);
//	assert(p4.second == 69);
//	assert(p3 == p4);
//	assert(p2 != p4);
//
//	Node<bool> n5(false);
//	Node<bool> n6(n5);
//	Node<bool> n7;
//	n7 = n5;
//	n6 = n7;
//	n5 = n6;
//
//	int *i2 = new int(1);
//	Node<int> n8(*i2);
//	Node<int> n9(n8);
//	Node<int> n10;
//	n10 = n8;
//	Node<int*> n11(i2);
//	Node<int*> n12(n11);
//	delete i2;
//	i2 = 0;
//
//	Object *o4 = new Object();
//	Node<Object> n13(*o4);
//	Node<Object> n14(n13);
//	Node<Object> n15;
//	n15 = n13;
//	delete o4;
//	o4 = 0;
//
//	LinkedList<int> l;
//	assert(l.size() == 0);
//	assert(l.empty());
//	l.push_front(1);
//	assert(l.size() == 1);
//	assert(!l.empty());
//	assert(l.front() == 1);
//	assert(l.back() == 1);
//	l.push_front(2);
//	assert(l.size() == 2);
//	assert(!l.empty());
//	assert(l.front() == 2);
//	assert(l.back() == 1);
//	l.push_back(3);
//	assert(l.size() == 3);
//	assert(!l.empty());
//	assert(l.front() == 2);
//	assert(l.back() == 3);
//	l.pop_back();
//	assert(l.size() == 2);
//	assert(!l.empty());
//	assert(l.front() == 2);
//	assert(l.back() == 1);
//
//	LinkedList<int> l1(l);
//	assert(l == l1);
//	assert(l1.size() == 2);
//	assert(!l1.empty());
//	l1.pop_back();
//	assert(l != l1);
//
//	Vector<int> v1;
//	v1.push_back(1);
//	assert(v1[0] == 1);
//	assert(v1.at(0) == 1);
//	assert(v1.back() == 1);
//	assert(v1.size() == 1);
//	assert(v1.capacity() == 1);
//	assert(!v1.empty());
//
//	v1.push_back(2);
//	assert(v1[1] == 2);
//	assert(v1.at(1) == 2);
//	assert(v1.back() == 2);
//	assert(v1.size() == 2);
//	assert(v1.capacity() == 2);
//	assert(!v1.empty());
//
//	v1.push_back(3);
//	assert(v1[2] == 3);
//	assert(v1.at(2) == 3);
//	assert(v1.back() == 3);
//	assert(v1.size() == 3);
//	assert(v1.capacity() == 4);
//	assert(!v1.empty());
//
//	v1.pop_back();
//	assert(v1.back() == 2);
//	assert(v1.size() == 2);
//	assert(v1.capacity() == 4);
//
//	Vector<int> v2(v1);
//	assert(v1 == v2);
//	assert(v2[0] == 1);
//	assert(v2[1] == 2);
//	assert(v2.size() == 2);
//	assert(v2.capacity() == 4);
//	assert(!v2.empty());
//	v1.pop_back();
//	v1.push_back(10);
//	assert(v1 != v2);
//
//	Vector<int> v3;
//	v3 = v2;
//	assert(v2 == v3);
//
//	LinkedList<int> l2;
//	for (int i = 0; i < 10; i++)
//	{
//		l2.push_back(i);
//	}
//
//	int temp  = 0;
//	for (LinkedList<int>::Iterator i = l2.begin(); i != l2.end(); ++i)
//	{
//		assert(*i == temp++);
//	}
//
//	temp = 0;
//	for (LinkedList<int>::Iterator i = l2.begin(); i != l2.end(); i++)
//	{
//		assert(*i == temp++);
//	}
//
//	LinkedList<int>::Iterator i = l2.end();
//	while (i != l2.begin())
//	{
//		assert(*--i == --temp);
//	}
//
//	temp = 9;
//	i = l2.end();
//	i--;
//	while (i != l2.begin())
//	{
//		assert(*i-- == temp--);
//	}
//
//	LinkedList<int> l3;
//	l3.push_back(1).push_back(2).push_back(4);
//	assert(l3.size() == 3);
//	assert(l3.front() == 1);
//	assert(l3.back() == 4);
//
//	Vector<unsigned int> v4;
//	v4.push_back(0).push_back(1).push_back(2).push_back(3);
//	for (unsigned int i = 0; i < v4.size(); i++)
//	{
//		assert(v4.at(i) == i);
//	}
//
//	Less<int> less;
//	assert(less(1, 2));
//
//	Greater<int> greater;
//	assert(greater(2, 1));
//
//	Node<int> n16(1);
//	Node<int> n17(2);
//	Node<int> n18(1);
//	assert(n16 < n17);
//	assert(n17 > n16);
//	assert(n16 <= n17);
//	assert(n17 >= n16);
//	assert(n16 != n17);
//	assert(n16 == n18);
//
//
//	Node<int, Greater<int> > n19(2);
//	Node<int, Greater<int> > n20(1);
//	assert(n19 < n20);
//
//	Comparable c1;
//	Comparable c2;
//	c1.x = 1;
//	c2.x = 2;
//	Node<Comparable, FunctionObject> n21(c1);
//	Node<Comparable, FunctionObject> n22(c2);
//	assert(n21 < n22);


	return 0;
}
