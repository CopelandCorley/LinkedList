#include <iostream>
#include "linkedlist.h"

int main(int argc, char **argv)
{
	LinkedList<int> c(5);
		c.append(4);
	std::cout<<"setup finished"<<std::endl<<std::endl;
	for(int j = 0; j < 1; j++){
		LinkedList<LinkedList<int> > b(c);
	}
	return 0;
}
