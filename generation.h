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

/// <summary>
/// Node structure for binary tree searches
/// </summary>
struct Node {
	Node(int data) :data(data), left(nullptr), right(nullptr) {};
	int data;
	Node* left;
	Node* right;
};
/// <summary>
/// Hash node structure for hash table searches
/// </summary>
struct HashNode {
	HashNode(int data) :data(data), next(nullptr) {};
	int data;
	HashNode* next;
};
/// <summary>
/// Generates a given number of primes, starting at 2
/// </summary>
/// <param name="numberOfValues">Number of primes to generate</param>
/// <returns>return pointer to an int vector containing the primes</returns>
std::vector<int>* primeNumbers(int numberOfValues);
/// <summary>
/// Creates a hash table from a given vector
/// </summary>
/// <param name="vector">Vector that contains the values</param>
/// <returns>A vector that contains HashNodes</returns>
std::vector<HashNode*>* hashTable(std::vector<int>* vector);
/// <summary>
/// Creates a root node that contains the vector values in binary tree form
/// </summary>
/// <param name="vector">Vector that contains the values</param>
/// <param name="start">Start point of vector</param>
/// <param name="stop">Stop point of vector</param>
/// <returns>Returns a root node containing the values from the vector</returns>
Node* binarySearchTree(std::vector<int>* vector, int start, int stop);
#endif