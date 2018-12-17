#include <iostream>
#include "linkedlist.h"

int main(int argc, char **argv)
{
	LinkedList<int> c(5);
	c.append(4);
	c.append(3);
	LinkedList<int> d(6);
	d.append(7);
	d.append(8);
	
	std::cout<<"setup finished"<<std::endl<<std::endl;
	for(int j = 0; j < 100; j++){
		LinkedList<LinkedList<int> > b(c);
		b.append(d);
	}
	return 0;
}
