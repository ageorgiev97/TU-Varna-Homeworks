// Демонстрация на оператор в класове
//
// Съдържа структура за обработка на цели числас оператори за присвояване,
// събиране и изваждане, както с друг обект така и с примитивен int
// 
// Изготвил: Даниел Атанасов Атанасов
// Фк. № 61662148
// Гр. СИТ 2б

#include <iostream>

using std::cout;
using std::endl;

// Използва се структура защото членовете са публични по подразбиране
struct Integer {
	// Стойността на числото
	int value;

	// Конструктори
	Integer(int i):
		value(i) { }

	Integer():
		value(0) { }

	// Оператор за взимане на стойността на обекта
	inline int operator()() const {
		return this->value;
	}

	// Оператори за събиране на два обекта или обект и примитивен int (отговорът е в нов обект)
	inline friend Integer operator+(Integer const &a, Integer const &b) {
		return Integer(a.value + b.value);
	}

	inline friend Integer operator+(Integer const &a, int const &b) {
		return Integer(a.value + b);
	}

	// Оператори за изваждане на два обекта или обект и примитивен int (отговорът е в нов обект)
	inline friend Integer operator-(Integer const &a, Integer const &b) {
		return Integer(a.value - b.value);
	}

	inline friend Integer operator-(Integer const &a, int const &b) {
		return Integer(a.value - b);
	}

	// Оператори за събиране на два обекта или обект и примитивен int (като се проненя единият обект)
	inline Integer& operator+=(Integer const &a) {
		this->value += a.value;
		return *this;
	}

	inline Integer& operator+=(int const &a) {
		this->value += a;
		return *this;
	}

	// Оператори за изваждане на два обекта или обект и примитивен int (като се проненя единият обект)
	inline Integer& operator-=(Integer const &a) {
		this->value -= a.value;
		return *this;
	}

	inline Integer& operator-=(int const &a) {
		this->value -= a;
		return *this;
	}

	// Оператори за присвояване на (стойността на) друг обект или на примитивен int
	inline Integer& operator=(int const &a) {
		this->value = a;
		return *this;
	}

	inline Integer& operator=(Integer const &a) {
		this->value = a.value;
		return *this;
	}
};

int main() {
	// Примери
	
	// По подразбиране, стойността е 0
	Integer i;
	cout << "Integer i" << endl;
	cout << "i() = " << i() << endl << endl;

	// Събиране и присвояване
	i += 10;
	cout << "i += 10" << endl;
	cout << "i() = " << i() << endl << endl;

	// Изваждане и присвояване
	i -= 9;
	cout << "i -= 9" << endl;
	cout << "i() = " << i() << endl << endl;

	// Присвояване
	i = 8;
	cout << "i = 8" << endl;
	cout << "i() = " << i() << endl << endl;

	// Събиране на два обекта и присвояване на получения сбор
	i = Integer(10) + Integer(3);
	cout << "i = Integer(10) + Integer(3)" << endl;
	cout << "i() = " << i() << endl << endl;

	// Събиране на обект и примитивен int и присвояване на получения сбор
	i = 8 + Integer(3);
	cout << "i = 8 + Integer(3)" << endl;
	cout << "i() = " << i() << endl << endl;

	// Изваждане на обект и примитивен int и присвояване на получения сбор
	i = 6 - Integer(4);
	cout << "i = 6 - Integer(4)" << endl;
	cout << "i() = " << i() << endl << endl;

	return 0;
}
