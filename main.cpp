#include <iostream>
#include "linkedlist.h"

int main(int argc, char **argv)
{
	
	//unit tests
	
	for(int i = 0; i < 100000; i++){
		LinkedList<int> c(5);
		c.append(4);//check for memory leaks
		c.append(3);
		LinkedList<int> d(6);
		d.append(7);
		d.append(8);
		for(int j = 0; j < 1000; j++){
			std::cout<<"Not segfaulting..."<<j * i + j<<"\n";
			LinkedList<LinkedList<int> > b(c);
			b.append(d);
			LinkedList<LinkedList<LinkedList<int> > > e;
			e.append(b);
			e.append(b);
			e.append(b);
			LinkedList<LinkedList<LinkedList<LinkedList<int> > > > f;
			f.prepend(e);
			f.append(e);
			LinkedList<LinkedList<LinkedList<int> > > g(e);
			f.insert(g, 1);
			for(int k = 0; k < 1000; k++)f.append(g);
			LinkedList<LinkedList<LinkedList<LinkedList<int> > > > h(f);
			h.remove(1);
			h.append(g);
			int aa = c.get(0);
			int bb = c[0];
			std::cout << "a: " << aa << "; b: " << bb << "\n";
			aa++;
			std::cout << "a: " << aa << "; b: " << bb << "\n";
			std::cout << "c.get(0): " << c.get(0) << "\n";
			c.get(0)++;
			std::cout << "c.get(0): " << c.get(0) << "\n";
		}
	}

	system("PAUSE");
	return 0;
}
