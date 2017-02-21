#include <iostream>

using namespace std;

template <typename T>
class Tree {
	class TreeItem {
		friend class Tree;
		
		T value;
		int count;
		
		TreeItem *children;

		TreeItem();
		
	public:
		
		T& operator[](int index);
	};



	Tree(T value, int maxChildren = 2);
};

int main(int argc, char *argv[]) {
	return 0;
}
