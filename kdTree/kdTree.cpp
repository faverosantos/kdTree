// kdTree.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <vector>
#include "kdTree.h"

int main()
{
	std::vector<float> initValue = { 3 }, searchValue = { 1 };

	kdTree myKd;

	initValue = { 3, 2 };
	myKd.root = myKd.insert(myKd.root, initValue);

	initValue = { -1, 2 };
	myKd.root = myKd.insert(myKd.root, initValue);

	initValue = { 8, -4 };
	myKd.root = myKd.insert(myKd.root, initValue);

	initValue = { -7, 9 };
	myKd.root = myKd.insert(myKd.root, initValue);

	initValue = { 5, 2 };
	myKd.root = myKd.insert(myKd.root, initValue);

	initValue = { 0, -1 };
	myKd.root = myKd.insert(myKd.root, initValue);

	initValue = { 6, 2 };
	myKd.root = myKd.insert(myKd.root, initValue);

	initValue = { 3, 7 };
	myKd.root = myKd.insert(myKd.root, initValue);

	initValue = { 2, -7 };
	myKd.root = myKd.insert(myKd.root, initValue);

	initValue = { 2, 2 };
	myKd.root = myKd.insert(myKd.root, initValue);

	initValue = { 8, 2 };
	myKd.root = myKd.insert(myKd.root, initValue);

	node* searchedNode = new node;
	searchValue = { 2 , 2 };

	searchedNode = myKd.search(myKd.root, searchValue);

	if (searchedNode == NULL) {
		std::cout << "Could not find specified search node!" << std::endl;
	}
	else {
		std::cout << "searchedNode->point[0]: " << searchedNode->point[0] << std::endl;
		std::cout << "searchedNode->point[1]: " << searchedNode->point[1] << std::endl;
		std::cout << "searchedNode->id: " << searchedNode->id << std::endl;
	}

	return 0;
}
