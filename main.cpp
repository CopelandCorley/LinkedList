#include <iostream>
#include "linkedlist.h"

int main(int argc, char **argv)
{
	
	
	for(int j = 0; j < 10000; j++){
		LinkedList<int> c(4);
		c.append(9);
		c.append(3);
		c.append(2);
		c.append(1);
		
		LinkedList<int> b(c);
		//std::cout<<"00000000000000000000000000000000000000000"<<std::endl;
		//std::cout<<b.get(0).get(0)<<" 1111111111111111111"<<std::endl;
		//std::cout<<b.get(0).get(0)<<" 2222222222222222222"<<std::endl;
		//std::cout<<b.get(0).get(0)<<" 3333333333333333333"<<std::endl;
		
		LinkedList<int> a(b);
		//std::cout<<"00000000000000000000000000000000000000000"<<std::endl;
		//std::cout<<a.get(0).get(0)<<std::endl;
		//std::cout<<a.get(1).get(0)<<std::endl;
		
		std::cout << j << std::endl;
		for(int i = 0; i < 5; i++){
			
			a.append(5);
			//std::cout<<a.getSize()<<std::endl;
		}
		//std::cout << a.getSize() << std::endl;
		
		for(int i = 0; i < 5; i++)
			a.deleteNode(0);
		std::cout << a.getSize() << std::endl;
	}
	
	int i = 0, a = 1, b = 5;
	while(i++ < 1000000000){a+=b;b-=a;}
	std::cout<<"a"<<a<<"b"<<b<<std::endl;
	return 0;
}
