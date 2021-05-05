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
	//Add primes until vector reaches given size
	while (primes->size() < numberOfValues) {
		bool prime = true;
		for (int j = 0; j < primes->size() && primes->at(j) * primes->at(j) <= i; j++){
			if (i % primes->at(j) == 0){
				//If found value is not prime, set flag to false
				prime = false;
				break;
			}
		}
		//If flag is true after check add prime to vector
		if (prime)
			primes->push_back(i);
		i++;
	}
	//Return pointer to prime vector
	return primes;
}

Node* binarySearchTree(std::vector<int>* vector, int start, int stop) {
	if (start <= stop) {
		int mid = (start + stop) / 2;
		//Create new node from middle
		Node* root = new Node(vector->at(mid));
		//Add children to left and right
		root->left = binarySearchTree(vector, start, mid - 1);
		root->right = binarySearchTree(vector, mid + 1, stop);
		return root;
	}
	else
		return nullptr;
}

std::vector<HashNode*>* hashTable(std::vector<int>* vector) {
	int size = vector->size() * 2;
	//Create new hash table with given size
	std::vector<HashNode*>* hashtable = new std::vector<HashNode*>(size);
	for (int i = 0; i < vector->size(); i++) {
		//Create new node and get middle index
		HashNode* firstNode = new HashNode(vector->at(i));
		int key = vector->at(i) % size;
		//If key is empty set it to first Node
		if (hashtable->at(key) == nullptr)
			hashtable->at(key) = firstNode;
		else {
			//If the key is not empty add second node
			HashNode* secondNode = hashtable->at(key);
			while (secondNode->next != nullptr) {
				secondNode = secondNode->next;
			}
			//Set next value to new node
			hashtable->at(key)->next = firstNode;
		}
	}
	return hashtable;
}