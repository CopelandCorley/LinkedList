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
			node(const T& a): val(a), next(nullptr){}
		}* head, * current;
		
		void init(const T& a){
			size = 1;
			head = new node(a);
			current = head;
		}
	public:
		LinkedList();
		LinkedList(const T& a);
		LinkedList(const LinkedList<T>& ll);
		LinkedList& operator= (const LinkedList<T>& ll);
		~LinkedList();
		
		void insert(const T& a, unsigned int index);
		void append(const T& a);
		void prepend(const T& a);
		void deleteNode(unsigned int index);
		T get(unsigned int i) const;
		int getSize() const;
};

template <typename T>
LinkedList<T>::LinkedList(){
	size = 0;
	head = nullptr;
}

template <typename T>
LinkedList<T>::LinkedList(const T& a){
	init(a);
}

template <typename T>
LinkedList<T>::~LinkedList(){
	while(size) deleteNode(0);
}

template <typename T>
void LinkedList<T>::insert(const T& a,unsigned int index){
	if(index > size){
		append(a);
	}else if(index < 1){
		prepend(a);
	}else{
		if(size == 0){
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
void LinkedList<T>::append(const T& a){
	if(size == 0){
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
void LinkedList<T>::prepend(const T& a){
	if(size == 0){
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
	node* itr = head;
	do{
	  if(!i) return itr->val;
		itr = itr->next;
	}while(i-- >= 0);
}

template <typename T>
int LinkedList<T>::getSize() const{
	return size;
}

//copy constructor
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& ll){
	size = 0;
	for(int i = 0; i < ll.getSize(); i++){
	  append(ll.get(i));
	}
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator =(const LinkedList<T>& ll){
	if(this != &ll){
		while(size) deleteNode(0);
		for(int i = 0; i < ll.getSize(); i++){
			append(ll.get(i));
	}
	}
	return *this;
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
