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
bool seqSearch(std::vector<int>* vector, int key);
bool binSearch(std::vector<int>* vector, int start, int stop, int key);
bool binTreeSearch(Node* root, int key);
bool hashSearch(std::vector<HashNode*>* hashTable, int key);
#endif