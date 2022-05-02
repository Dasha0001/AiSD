#include <iostream>
#include "RBTreeRealisation.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");

	RBTree<size_t, int> newTree;
	newTree.insert(55, 5);
	newTree.insert(40, 88);
	newTree.insert(65, 10);
	newTree.insert(75, 15);
	newTree.insert(60, 6);
	newTree.insert(57, 11);
	cout << "get_keys:" << *newTree.get_keys() << "\n";
	cout << "get_values:" << *newTree.get_values() << "\n";
	newTree.remove(40);
	newTree.remove(60);
	newTree.remove(57);
	newTree.remove(75);
	newTree.remove(65);
	cout << "After Remove get_keys: " << *newTree.get_keys() << "\n";
	cout << "After Removeget_values:" << *newTree.get_values() << "\n";

	newTree.Find(55);
	cout << "PrintAll" << "\n";
	newTree.Print();
	newTree.clear();

	return 0;
}

