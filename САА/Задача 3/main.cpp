#include <iostream>

#include "list.h"

using namespace std;

int main(int argc, char *argv[])
{
	auto *l = new list<int>(0);
	l->append(1);
	l->append(0);
	l->append(1);
	l->append(1);

	l->to_pivot();
	for (int i =0; i < l->count(); i++, l->next())
		cout << l->current() << endl;

	l->clear_duplicates();

	cout << endl;

	l->to_pivot();
	for (int i =0; i < l->count(); i++, l->next())
		cout << l->current() << endl;

	delete l;

	return 0;
}
