#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
/////////////////////////////////////make rule of five complient
template <typename T>
class LinkedList{
	private:
		unsigned int size;
		
		struct node{
			T val;
			node* next;
			node(T a){
				val = T(a);
				next = nullptr;
			}
		}* head, * current;
		
		void init(T a){
			//std::cout<<"initializing: "<<&a<<std::endl;
			size = 1;
			head = new node(a);
			current = head;
		}
	public:
		LinkedList();
		LinkedList(T a);
		LinkedList(const LinkedList<T>& ll);
		~LinkedList();
		
		void insert(T a, unsigned int index);
		void append(T a);
		void prepend(T a);
		void deleteNode(unsigned int index);
		T get(unsigned int i) const;
		int getSize() const;
};

template <typename T>
LinkedList<T>::LinkedList(){
	//std::cout<<"creating: "<<this;
	size = 0;
	//std::cout<<" size: "<<size<<std::endl;
	head = nullptr;
}

template <typename T>
LinkedList<T>::LinkedList(T a){
	//std::cout<<"creating: "<<this<<std::endl;
	init(a);
	//std::cout<<" size: "<<size<<std::endl;
}

template <typename T>
LinkedList<T>::~LinkedList(){
	//std::cout<<"destroying: "<<this<<" size: "<<size<<std::endl;
	unsigned int i = size;
	while(i) deleteNode(--i);
}

template <typename T>
void LinkedList<T>::insert(T a,unsigned int index){
	//std::cout<<"inserting: "<<a<<" size: "<<size<<std::endl;
	if(index > size){
		append(a);
	}else if(index < 1){
		prepend(a);
	}else{
		if(head == nullptr){
			init(a);
		}
		else{
			node* n;
			n = new node(a);
			int count = 0;
			while(count++ < index - 1){
				current = current->next;
			}
			n->next = current->next;
			current->next = n;
			current = head;
			size++;
		}
	}
}

template <typename T>
void LinkedList<T>::append(T a){
	//std::cout<<"appending: "<<&a<<" size: "<<size<<std::endl;
	if(head == nullptr){
		init(a);
	}else{
		node* n;
		n = new node(a);
		while(current->next != nullptr){
			current = current->next;
		}
		current->next = n;
		current = head;
		size++;
	}
}

template <typename T>
void LinkedList<T>::prepend(T a){
	//std::cout<<"prepending: "<<a<<" size: "<<size<<std::endl;
	if(head == nullptr){
		init(a);
	}
	else{
		node* n;
		n = new node(a);
		n->next = head;
		head = n;
		current = head;
		size++;
	}
}

template <typename T>
void LinkedList<T>::deleteNode(unsigned int index){
	//std::cout<<"deleting: "<<index<<" size: "<<size<<std::endl;
	if(size > 0 && index < size){
		if(index == 0){
			node* temp = head;
			head = head->next;
			delete temp;
			temp = nullptr;
			current = head;
		}
		else{
			unsigned int count = 0;
			while(count++ < index - 1){
				current = current->next;
			}
			node* temp = current->next;
			current->next = current->next->next;
			delete temp;
			temp = nullptr;
			current = head;
		}
		size--;
		if(!size) head = nullptr;
	}
}

//ensure !(i >= size || i < 0 || size == 0) before using
template <typename T>
T LinkedList<T>::get(unsigned int i) const{
	//std::cout<<"getting: "<<i<<" size: "<<size<<std::endl;
	node* itr = head;
	do{
		if(!i) return itr->val;
		itr = itr->next;
	}while(i-- >= 0);
	//std::cout<<"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOPPPPPPSSS!!"<<std::endl;
}

template <typename T>
int LinkedList<T>::getSize() const{
	//std::cout<<"getting size: "<<size<<std::endl;
	return size;
}

//copy constructor
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& ll){
	std::cout<<"copying "<<&ll;
	size = 0;
	head = nullptr;
	for(int i = 0; i < ll.getSize(); i++){
		append(ll.get(i));
	}
	std::cout<<" size: "<<size<<std::endl;
}

//In a tropical region, far away,
//atop the most equatorial mountain,
//there lived one singular tadpole.
//"Quite a strange place to call home
//for a tadpole," you might think. Well, it 
//was not so strange, in fact, because,
//surrounding this tadpole, providing her with 
//all of the nourishment and shelter for the past
//four weeks, was a puddle.
//A tiny puddle. 
//A puddle that looked like it once had
//been a rather modest pond.
//But this puddle was not a pond. 
//No, I assure you, this puddle was, indeed,
//a puddle. And beneath this puddle stood the most
//equatorial of mountains upon which sat the 
//most equatorial puddle containing the 
//most equatorial tadpole.
//
//Barely begun to metamorphose.
//And this tadpole was just realizing that the great, big pond
//she called home was feeling a bit more cramped than usual.
//Just last week it took her nearly a half hour
//to swim the perimeter of her 
//
//Dreadful existence as a tadpole.
//
//She could hop! And she could cling! And she could climb!
//So she hopped and clinged and climbed her way down the 
//mountain. Fulfillment.
#endif