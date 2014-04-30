#include "Node.h"
#include "Pair.h"
#include "LinkedList.h"
#include "Vector.h"
#include <cassert>

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
//	v1.at(3);

	return 0;
}
