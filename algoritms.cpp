/*
2021-04-27
André Nordlund
anno1907
Datastrukturer och algoritmer DT046G
Labb 3
*/
#include "algoritms.h"
bool seqSearch(std::vector<int>* vector, int key) {
	//Searches from beginning to end
	for (int i = 0; i < vector->size(); i++) {
		if (key == vector->at(i))
			return true;
	}
	return false;
}
bool binSearch(std::vector<int>* vector, int start, int stop, int key) {
	//If start and stop is not same index
	if (start <= stop) {
		//Get middle index
		int mid = (start + stop) / 2;
		//If key is lower than mid value
		//Get the first half else second half
		if (key < vector->at(mid))
			binSearch(vector, start, mid - 1, key);
		else if (key > vector->at(mid))
			binSearch(vector, mid + 1, stop, key);
		else
			return true;
	}
	else
		return false;
}
bool binTreeSearch(Node* root, int key) {
	Node* pointer = root;
	while (pointer != nullptr) {
		//Traverse left or right depending on key value
		if (key < pointer->data)
			pointer = pointer->left;
		else if (key > pointer->data)
			pointer = pointer->right;
		else
			return true;
	}
	return false;
}
bool hashSearch(std::vector<HashNode*>* hashTable, int key) {
	int key_pos = key % hashTable->size();
	//Get index of key value
	while (hashTable->at(key_pos) != nullptr) {
		//If key is found return true
		//else traverse hash table
		if (hashTable->at(key_pos)->data == key)
			return true;
		else 
			hashTable->at(key_pos) = hashTable->at(key_pos)->next;
	}
	return false;
}