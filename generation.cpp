/*
2021-04-27
André Nordlund
anno1907
Datastrukturer och algoritmer DT046G
Labb 3
*/
#include "generation.h"

std::vector<int>* primeNumbers(int numberOfValues) {
	std::vector<int>* primes = new std::vector<int>;
	primes->push_back(2);
	int i = 3;
	while (primes->size() < numberOfValues) {
		bool prime = true;
		for (int j = 0; j < primes->size() && primes->at(j) * primes->at(j) <= i; j++){
			if (i % primes->at(j) == 0){
				prime = false;
				break;
			}
		}
		if (prime)
			primes->push_back(i);
		i++;
	}
	return primes;
}

Node* binarySearchTree(std::vector<int>* vector, int start, int stop) {
	if (start <= stop) {
		int mid = (start + stop) / 2;
		Node* root = new Node(vector->at(mid));
		root->left = binarySearchTree(vector, start, mid - 1);
		root->right = binarySearchTree(vector, mid + 1, stop);
		return root;
	}
	else
		return nullptr;
}

std::vector<HashNode*>* hashTable(std::vector<int>* vector) {
	int size = vector->size() * 2;
	std::vector<HashNode*> hashtable(size);
	for (int i = 0; i < vector->size(); i++) {
		HashNode* firstNode = new HashNode(vector->at(i));
		int key = vector->at(i) % size;
		if (hashtable[key] == nullptr) {
			hashtable[key] = firstNode;
		}
		else {
			HashNode* secondNode = hashtable[key];
			while (secondNode->next != nullptr) {
				secondNode = secondNode->next;
			}
			hashtable[key]->next = firstNode;
		}
	}
	return &hashtable;
}