#include "Node.h"
#include "Pair.h"
#include <cassert>

class Object{ };

int main()
{
	Node<int> n1(1);
	int *i = n1.data();
	assert(*i == 1);

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
}
