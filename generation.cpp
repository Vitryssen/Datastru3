/*
2021-04-27
André Nordlund
anno1907
Datastrukturer och algoritmer DT046G
Labb 3
*/
#include "generation.h"

std::vector<int>* primeNumbers(int numberOfValues) {
	std::vector<bool> primes(numberOfValues + 1, true);
	for (int p = 2; p * p <= numberOfValues; p++)
	{
		if (primes.at(p))
		{
			for (int i = p * p; i <= numberOfValues; i += p)
				primes.at(i) = false;
		}
	}
	std::vector<int>* output = new std::vector<int>;
	for (int i = 2; i < numberOfValues; i++) {
		if (primes.at(i))
			output->push_back(i);
	}
	return output;
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

std::vector<HashNode*> hashTable(std::vector<int>* vector) {
	int size = vector->size() * 2;
	std::vector<HashNode*>hashTable(size);
	for (int i = 0; i < vector->size(); i++) {
		HashNode* firstNode = new HashNode(vector->at(i));
		int key = vector->at(i) % size;
		if (hashTable[key] == nullptr) {
			hashTable[key] = firstNode;
		}
		else {
			HashNode* secondNode = hashTable[key];
			while (secondNode->next != nullptr) {
				secondNode = secondNode->next;
			}
			hashTable[key]->next = firstNode;
		}
	}
	return hashTable;
}