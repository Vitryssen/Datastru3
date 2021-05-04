/*
2021-04-27
André Nordlund
anno1907
Datastrukturer och algoritmer DT046G
Labb 3
*/
#ifndef GENERATION_H
#define GENERATION_H
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

struct Node {
	Node(int data) :data(data), left(nullptr), right(nullptr) {};
	int data;
	Node* left;
	Node* right;
};

struct HashNode {
	HashNode(int data) :data(data), next(nullptr) {};
	int data;
	HashNode* next;
};

std::vector<int>* primeNumbers(int numberOfValues);
std::vector<HashNode*>* hashTable(std::vector<int>* vector);
Node* binarySearchTree(std::vector<int>* vector, int start, int stop);


#endif