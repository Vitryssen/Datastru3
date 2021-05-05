/*
2021-04-27
André Nordlund
anno1907
Datastrukturer och algoritmer DT046G
Labb 3
*/
#ifndef ALGORITMS_H
#define ALGORITMS_H
#include "generation.h"
#include <vector>
/// <summary>
/// Searches for a given value in a given vector.
/// Starts at the begining and searches until the end.
/// </summary>
/// <param name="vector">Vector to contain the values to search in</param>
/// <param name="key">Value to search for</param>
/// <returns>True if it finds key else false</returns>
bool seqSearch(std::vector<int>* vector, int key);
/// <summary>
/// Searches for a given value in a given vector using binary search.
/// </summary>
/// <param name="vector">Vector that contains values to search in</param>
/// <param name="start">Start point</param>
/// <param name="stop">Stop point</param>
/// <param name="key">Value to search for</param>
/// <returns>True if it finds key else false</returns>
bool binSearch(std::vector<int>* vector, int start, int stop, int key);
/// <summary>
/// Searches for a given value in a given vector using binary tree search.
/// </summary>
/// <param name="root">A root with type Node</param>
/// <param name="key">Value to search for</param>
/// <returns>True if it finds key else false</returns>
bool binTreeSearch(Node* root, int key);
/// <summary>
/// Searches for a given value in a given vector using hash search.
/// </summary>
/// <param name="hashTable">A hash table</param>
/// <param name="key">Value to search for</param>
/// <returns>True if it finds key else false</returns>
bool hashSearch(std::vector<HashNode*>* hashTable, int key);
#endif