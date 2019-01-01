#include <iostream>
#include "linkedlist.h"

int main(int argc, char **argv)
{
	
	//unit tests
	
	//check for memory leaks
	/*
	for(int i = 0; i < 100000; i++){
		LinkedList<int> c(5);
		c.append(4);
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
			LinkedList<LinkedList<LinkedList<int> >> g(e);
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
	}*/
/*
	//check insert works
	for(int i = 0; i < 1000; i++){
		LinkedList<int> ll(5);
		for(int j = 0; j < 10; j++){
			ll.insert(6, 1);
			std::cout << ll.get(0) << " " << ll.get(1) << "\n";
			std::cout << ll.count() << "\n";
			ll.remove(0);
			std::cout << ll.count() << "\n";
			ll.remove(0);
			std::cout << ll.count() << "\n";
			ll.insert(8, 0);
			std::cout << ll.count() << "\n";
			ll.insert(9, 0);
			std::cout << ll.count() << "\n";
			std::cout << ll.get(0) << " " << ll.get(1) << "\n";
			ll.remove(0);
			std::cout << ll.count() << "\n";
			//ll.remove(0);
			//std::cout << ll.count() << "\n";
		}
	}

/*
	//test move constructor + cool progress bar
	int times = 1000;
	for(int i = 0; i < times; i++)
	{
		std::cout << '[';
		int j;
		for (j = 0; j < 100 * i / times; j++) {
			std::cout << 'x';
		}
		for (j = 100 - j; j > 0; j--) {
			std::cout << ' ';
		}
		std::cout << ']';
		LinkedList<int> linky[1];
		linky[0] = LinkedList<int>(5);
		system("CLS");
	}
*/
	system("PAUSE");
	return 0;
}
