#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H
#include <iostream>
template <typename T>
class list
{
	struct list_item {
		T value;
		list_item *previous;
		list_item *next;

		list_item(T value, list_item *next, list_item *previous);
		list_item(T value);
	};

	list_item *_pivot;
	list_item *_current;

	int _count;

public:
	inline void append(T value);
	inline void preppend(T value);
	inline void to_pivot();

	void remove_current();

	inline int count();
	inline T current();

	T next();
	T previous();

	void clear();
	void clear_duplicates();
	void init(T value);

	list(T value);
	list();
	~list();
};

template <typename T>
list<T>::list_item::list_item(T value, list_item *next, list_item *previous):
	value(value),
	previous(previous),
	next(next) {

	this->next->previous = this;
	this->previous->next = this;
}

template <typename T>
list<T>::list_item::list_item(T value):
	value(value),
	previous(this),
	next(this) { }

template <typename T>
inline void list<T>::append(T value) {
	new list_item(value, this->_current->next, this->_current);
	this->_count++;
}

template <typename T>
inline void list<T>::preppend(T value){
	new list_item(value, this->_current, this->_current->previous);
	this->_count++;
}

template <typename T>
inline void list<T>::to_pivot(){
	this->_current = this->_pivot;
}

template <typename T>
void list<T>::remove_current() {
	this->_current->previous->next = this->_current->next;
	this->_current->next->previous = this->_current->previous;

	this->_count--;

	delete this->_current;
}

template <typename T>
inline int list<T>::count() {
	return this->_count;
}

template <typename T>
inline T list<T>::current() {
	return this->_current->value;
}

template <typename T>
T list<T>::next() {
	this->_current = this->_current->next;
	return this->current();
}

template <typename T>
T list<T>::previous() {
	this->_current = this->_current->previous;
	return this->current();
}

template <typename T>
void list<T>::clear() {
	list_item *i = _pivot;

	do
		delete i->previous;
	while ((i = i->next) != _pivot);

	this->_current = nullptr;
	this->_pivot = nullptr;
	this->_count = 0;
}

template <typename T>
void list<T>::clear_duplicates() {
	list_item *l1 = _pivot;

	do {
		list_item *l2 = l1->next;

		do {
			if (l1->value == l2->value) {
				l1->next = l2->next;
				l2->next->previous = l1;
				delete l2;
				l2 = l1;

				this->_count--;
			}
		} while ((l2 = l2->next) && l2 != _pivot);
		std::cout<<"asdf"<<std::endl;
	} while ((l1 = l1->next) && l1 != _pivot);

}

template <typename T>
void list<T>::init(T value) {
	if (!this->_count) {
		this->_pivot = new list_item(value);
		this->_current = this->_pivot;
		this->_count = 1;
	}
}

template <typename T>
list<T>::list(T value):
	_pivot(new list_item(value)),
	_current(_pivot),
	_count(1) {

	this->init(value);
}

template <typename T>
list<T>::list():
	_pivot(nullptr),
	_current(nullptr),
	_count(0) { }

template <typename T>
list<T>::~list() {
	this->clear();
}

#endif // DLINKEDLIST_H
