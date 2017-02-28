#include <iostream>

using std::cin;
using std::cout;
using std::endl;

template <typename T>
class list {
	struct list_item {
		list_item *previous;
		list_item *next;

		T value;

		list_item(T value) :
			value(value) { }
	};

	list_item *first;
	list_item *last;

	void init(T value) {
		this->first = new list_item(value);
		this->first->previous = this->first;
		this->first->next = this->first;
		this->last = this->first;
	}

public:
	void print() {
		if (this->first != nullptr) {
			list_item *a = this->first;

			do {
				cout << a->value << endl;
				a = a->next;
			} while (a != nullptr);
		}
	}

	void append(T value) {
		if (this->last != nullptr) {
			list_item *n = new list_item(value);
			n->previous = this->last;
			n->next = nullptr;
			this->last->next = n;
			this->last = n;
		} else
			this->init(value);
	}

	void preppend(T value) {
		if (this->first != nullptr) {
			list_item *n = new list_item(value);
			n->next = this->first;
			n->previous = nullptr;
			this->first->previous = n;
			this->first = n;
		} else
			this->init(value);
	}

	void purge() {
		if (this->first != nullptr) {
			list_item *a, *b, *c;
			a = this->first;

			while (a != nullptr && a->next != nullptr)
			{
				b = a;

				while (b->next != nullptr)
				{
					if (a->value == b->next->value)
					{
						c = b->next;
						b->next = b->next->next;
						if (b->next != nullptr)
							b->next->previous = b;
						delete c;
					}
					else
						b = b->next;
				}
				this->last = b;

				a = a->next;
			}
		}
	}

	list():
		first(nullptr),
		last(nullptr) {	}

	list(T value) {
		this->init(value);
	}

	~list() {
		if (this->first != nullptr) {
				list_item *a = this->first;

				do {
					a = a->next;
					delete a->previous;
				} while (a != this->last);
				delete a;
		}
	}
};

int main() {
	list<int> a;
	int n;
	cout << "Enter count of list items: ";
	cin >> n;
	while (n--) {
		int m;
		cout << "Enter a list item: ";
		cin >> m;
		a.append(m);
	}
	cout << "You entered the following list: " << endl;
	a.print();
	cout << "Your list after the duplicates have been removed: " << endl;
	a.purge();
	a.print();
	return 0;
}