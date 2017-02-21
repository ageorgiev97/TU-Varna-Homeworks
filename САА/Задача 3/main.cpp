#include <iostream>

#include "list.h"

using namespace std;

int main(int argc, char *argv[])
{
	auto *l = new list<int>(0);
	l->append(1);
	l->next();
	l->append(0);
	l->next();
	l->append(1);
	l->next();
	l->append(1);
	l->next();

	l->to_pivot();
	for (int i =0; i < l->count(); i++, l->next())
		cout << l->current() << endl;

	l->clear_duplicates();
	l->to_pivot();
	cout << endl;
	for (int i =0; i < l->count(); i++, l->next())
		cout << l->current() << endl;

	std::cout<<"asdf"<<std::endl;
	delete l;
	std::cout<<"asdf"<<std::endl;

	return 0;
}
