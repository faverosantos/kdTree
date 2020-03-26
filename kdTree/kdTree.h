#pragma once
#include <cstddef>
#include <vector>

#define k 2

struct node {
	std::vector<float> point;
	int id;
	node* left;
	node* right;
};

struct kdTree {
	node* root;
	int nodesCounter = 0;

	kdTree(){
		root = NULL;
	}

	kdTree(std::vector<float> initVal) {
		root->point = initVal;
		root->id = 0;
		root->right = root->left = NULL;
	}

	node* newNode(std::vector<float> value, int id) {
		node* localNode = new node;
		localNode->point = value;
		localNode->id = id;
		localNode->left = NULL;
		localNode->right = NULL;

		return localNode;
	}

	node* search(node* recursiveNode, std::vector<float> value) {
		return searchHelper(recursiveNode, value, 0);
	}

	node* searchHelper(node* recursiveNode, std::vector<float> value, int depth) {
		
		static node* foundNode;

		if (value != recursiveNode->point){

			// Determine the depth of the tree to insert the roots
			int cd = depth % k;

			if ((recursiveNode->right == NULL) && (recursiveNode->left == NULL)) {
				foundNode = NULL;
			}
			else if (value[cd] >= recursiveNode->point[cd]) {
				searchHelper(recursiveNode->right, value, ++depth);
			}
			else if (value[cd] < recursiveNode->point[cd]) {
				searchHelper(recursiveNode->left, value, ++depth);
			}

		}
		else if (value == recursiveNode->point) {
			foundNode = newNode(recursiveNode->point, recursiveNode->id);
		}

		return foundNode;
	}

	node* insert(node* recursiveNode, std::vector<float> value) {
		return insertHelper(recursiveNode, value, 0);
	}

	node* insertHelper(node* recursiveNode, std::vector<float> value, int depth) {
		
		if (recursiveNode == NULL) {
			recursiveNode = newNode(value, nodesCounter++);
		}
		else {

			// Determine the depth of the tree to insert the roots
			int cd = depth % k;

			if (value[cd] >= recursiveNode->point[cd]) {
				if (recursiveNode->right == NULL) {
					recursiveNode->right = newNode(value, nodesCounter++);
				}
				else {
					insertHelper(recursiveNode->right, value, ++depth);
				}
			}
			else if (value[cd] < recursiveNode->point[cd]) {
				if (recursiveNode->left == NULL) {
					recursiveNode->left = newNode(value, nodesCounter++);
				}
				else {
					insertHelper(recursiveNode->left, value, ++depth);
				}
			}
		}
		return recursiveNode;
	}
};
