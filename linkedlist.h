#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdexcept>
#include <iostream>

template <typename T>
class LinkedList{
	private:
		unsigned int size;
		
		struct node{
			T val;
			node* next;
			node(const T& a): val(a), next(nullptr){}
		}* head, * current;
		
		void inline init(const T& a){
			size = 1;
			head = new node(a);
			current = head;
		}
	public:
		LinkedList();
		virtual ~LinkedList() noexcept;
		LinkedList(const T& a);
		LinkedList(const LinkedList<T>& rhs);
		LinkedList(LinkedList<T>&& rhs) noexcept;
		LinkedList& operator= (const LinkedList<T>& rhs);
		LinkedList& operator= (LinkedList<T>&& rhs) noexcept;
		T& operator[] (const unsigned int index);
		
		void insert(const T& a, unsigned int index);
		void append(const T& a);
		void prepend(const T& a);
		void remove(unsigned int index);
		T& get(unsigned int i) const;
		int count() const;
};

template <typename T>
LinkedList<T>::LinkedList() : size(0), head(nullptr) {}

template <typename T>
LinkedList<T>::LinkedList(const T& a) : head(new node(a)), current(head), size(1){}

template <typename T>
LinkedList<T>::~LinkedList() noexcept{
	while (size) remove(0);
}

//inserts an element at the specified index of the linked list
template <typename T>
void LinkedList<T>::insert(const T& a, unsigned int index){
	if(index < 0 || index > size) throw std::out_of_range("Index out of range in method 'void insert(const T& a, unsigned int index)' in LinkedList<T>");
	if(size == 0){
		init(a);
	}
	else if(index == 0){//prepend logic
		node* n;
		n = new node(a);
		n->next = head;
		head = n;
		current = head;
		size++;
	}
	else{//insert+append logic
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

//appends an element to the end of the linked list
template <typename T>
void LinkedList<T>::append(const T& a){
	insert(a, size);
}

//prepends an element to the beginning of the linked list
template <typename T>
void LinkedList<T>::prepend(const T& a){
	insert(a, 0);
}

//removes the element at specified index
template <typename T>
void LinkedList<T>::remove(unsigned int index){
	if(index < 0 || index >= size) throw std::out_of_range("Index out of range in method 'void remove(unsigned int index)' in LinkedList<T>");
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

//returns a reference to the element at specified index
template <typename T>
T& LinkedList<T>::get(unsigned int index) const{
	if(index < 0 || index >= size) throw std::out_of_range("Index out of range in method 'T& get(unsigned int index) const' in LinkedList<T>");
	node* itr = head;
	do{
	  if(!index) return itr->val;
		itr = itr->next;
	}while(index-- >= 0);
}

//returns the size of the linked list
template <typename T>
int LinkedList<T>::count() const{
	return size;
}

//copy constructor
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& rhs): size(0){
	for(int i = 0; i < rhs.count(); i++){
	  append(rhs.get(i));
	}
}

//move constructor
template <typename T>
LinkedList<T>::LinkedList(LinkedList<T>&& rhs) noexcept : head(rhs.head), current(rhs.current), size(rhs.size) {
	rhs.head = rhs.current = nullptr;
	size = 0;
}

//copy-assignment operator
template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs){
	if(this != &rhs){
		while(size) remove(0);
		for(int i = 0; i < rhs.count(); i++){
			append(rhs.get(i));
		}
	}
	return *this;
}

//move-assignment operator
template<typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>&& rhs) noexcept {
	head = current = rhs.head;
	size = rhs.size;
	rhs.size = 0;
	rhs.head = rhs.current = nullptr;
	return *this;
}

//[] operator
template <typename T>
T& LinkedList<T>::operator [](const unsigned int index){
	return get(index);
}
#endif
