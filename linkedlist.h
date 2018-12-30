#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdexcept>

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
		LinkedList(const LinkedList<T>& ll);
		LinkedList& operator= (const LinkedList<T>& ll);
		T& operator[] (const unsigned int index);
		
		void insert(const T& a, unsigned int index);
		void append(const T& a);
		void prepend(const T& a);
		void remove(unsigned int index);
		T& get(unsigned int i) const;
		int count() const;
};

template <typename T>
LinkedList<T>::LinkedList(): size(0), head(nullptr){}

template <typename T>
LinkedList<T>::LinkedList(const T& a) : head(new node(a)), current(head), size(1){}

template <typename T>
LinkedList<T>::~LinkedList() noexcept{
	while(size) remove(0);
}

//inserts an element at the specified index of the linked list
template <typename T>
void LinkedList<T>::insert(const T& a, unsigned int index){
	if(index < 0 || index > size) throw std::out_of_range("Index out of range in method 'void insert(const T& a, unsigned int index)' in LinkedList<T>");
	if(size == 0){
		init(a);
	}
	else if(index == 0){//logic to prepend
		node* n;
		n = new node(a);
		n->next = head;
		head = n;
		current = head;
		size++;
	}
	else{//insert logic
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
LinkedList<T>::LinkedList(const LinkedList<T>& ll): size(0){
	for(int i = 0; i < ll.count(); i++){
	  append(ll.get(i));
	}
}

//copy-assignment operator
template <typename T>
LinkedList<T>& LinkedList<T>::operator =(const LinkedList<T>& ll){
	if(this != &ll){
		while(size) remove(0);
		for(int i = 0; i < ll.count(); i++){
			append(ll.get(i));
		}
	}
	return *this;
}

//[] operator
template <typename T>
T& LinkedList<T>::operator [](const unsigned int index){
	return get(index);
}
//Atop an impossibly tall mountain 
//there sat a lonely, crumbly boulder.
//Weathered by age and crippling loneliness, each passing day .
//Of course, he hadn't always been so lonely. The mountaintop was once host
//to a thriving community of stones of all shapes and sizes, but they 
//had slowly vanished over the years until he was finally the last. His friend George had 
//eroded into the pile of dust to his left some millenia ago, and Sam, who quite 
//liked living her life on the edge, had been knocked loose by a tremor
//and fell down the mountain some four centuries prior. His most recent friend was a little 
//tadpole who he had noticed in the spring, but she left once her pond began to dry up.
//Falls down mountain due to frog. Becomes sediment. Meets other sediment. Becomes too crowded. Becomes sedimentary
//rock underground.



//Atop an mountain,                             //tadpole knocks boulder down
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
