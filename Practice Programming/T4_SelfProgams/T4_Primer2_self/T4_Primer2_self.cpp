// Демонстрация на абстрактни класове, наследяване и полиморфизъм
//
// Съдържа един абстрактен клас с една виртуален функция,
// и няколко наследяващи го класове с различни дефиниции за нея
// Всеки от тях инициализира майчиния клас с различна стойност в конструктора
//
// Изготвил: Даниел Атанасов Атанасов
// Фк. № 61662148
// Гр. СИТ 2б

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

// Абстрактен клас
class animal {
	string species;

protected:
	animal(string const &species):
		species(species) { }

public:
	// Една чисто виртуална функция (която определя класа като абстрактен)
	virtual string talk() const = 0;
	// Функция за връщане на името на наследяващия го клас
	// Функцията не е виртуална, но член променливате се задава при инициализацията
	// на съответния наследник
	string getSpecies() {
		return species;
	}
	virtual ~animal() { }
};

// Четири класове наследяващи горния
// Различават се по дефиницията на виртуалната функция
// и по аргумента подаден на конструктора на майчиния клас
struct pig: animal {
	virtual string talk() const {
		return "Oink!";
	}
	pig():
		animal("Pig") { }
};

struct cat: animal {
	virtual string talk() const {
		return "Meow!";
	}
	cat():
		animal("Cat") { }
};

struct dog: animal {
	virtual string talk() const {
		return "Woof!";
	}
	dog():
		animal("Dog") { }
};

struct cow: animal {
	virtual string talk() const {
		return "Moo!";
	}
	cow():
		animal("Cow") { }
};

int main(int argc, char *argv[])
{
	// Масив от animal
	// Той е абстрактен клас така че може да се запълни
	// само и единствено със обекти от наследяващи го класове
	animal *arr[] = {
		new dog(),
		new cat(),
		new pig(),
		new cow()
	};

	for (unsigned i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		// Изписва се името и "звука" на наследниците, без всъщност да се знае техният динамичен тип
		// Той се се намира докато програмата върви, а не по време на компилацията
		// Това е нужно само при ползване на виртуалната функция
		// Тъй като член променливите не засягат дефинициите на функциите,
		// втората функция се "намира" по време на компилацията зашото няма друга такава
		cout << "The " << arr[i]->getSpecies() << " goes " << arr[i]->talk() << endl;
		delete arr[i];
	}

	return 0;
}