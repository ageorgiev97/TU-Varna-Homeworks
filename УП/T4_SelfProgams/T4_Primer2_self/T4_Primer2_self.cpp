#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class animal {
	string species;

protected:
	animal(string const &species):
		species(species) { }

public:
	virtual string talk() const = 0;
	string getSpecies() {
		return species;
	}
	virtual ~animal() { }
};

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
	animal *arr[] = {
		new dog(),
		new cat(),
		new pig(),
		new cow()
	};

	for (unsigned i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		cout << "The " << arr[i]->getSpecies() << " goes " << arr[i]->talk() << endl;
		delete arr[i];
	}

	return 0;
}
