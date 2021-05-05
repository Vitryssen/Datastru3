/*
2021-04-27
André Nordlund
anno1907
Datastrukturer och algoritmer DT046G
Labb 3
*/
#include "timer.h"
#include <iostream>
void time_all(std::vector<int>* (*generate_data_funk)(int size), int start, int end, int increment)
{
	std::vector<std::string> fileNames = { "seqSearch.data", "binSearch.data", "binTreeSearch.data", "hashSearch.data"};
	clearFiles(fileNames);
	auto seq = [](std::vector<int>* vector, int key) {seqSearch(vector, key); };
	auto bin = [](std::vector<int>* vector, int key) {binSearch(vector, 0, vector->size()-1, key); };
	auto binTree = [](std::vector<int>* vector, int key) {binTreeSearch(binarySearchTree(vector, 0, vector->size()-1), key); };
	auto hash = [](std::vector<int>* vector,int key) {hashSearch(hashTable(vector), key); };

	for (int N = start; N <= end; N += increment)
	{
		auto container = generate_data_funk(N);
		time_calculation(seq, container, fileNames[0]);
		time_calculation(bin, container, fileNames[1]);
		time_calculation(binTree, container, fileNames[2]);
		time_calculation(hash, container, fileNames[3]);
		delete container;
	}
}

void time_calculation(void(*sort_funk)(std::vector<int>*, int), std::vector<int>* container, std::string fileName)
{
	double samples = 50;
	double squareTime = 0;
	double totalTime = 0;
	double avgTime;
	double stdDev;
	double dif_time;

	for (int i = 0; i < samples; i++)
	{
		auto current_time = time(sort_funk, container);
		totalTime += current_time;
		squareTime += pow(current_time, 2);
	}

	avgTime = totalTime / samples;
	dif_time = pow(totalTime, 2) / samples;
	stdDev = sqrt((squareTime - dif_time) / (samples - 1));


	std::string output = std::to_string(container->size()) + "\t" + std::to_string(avgTime) + "\t" + std::to_string(stdDev) + "\t#" + std::to_string(samples) + "\n";
	write(fileName, output);
}
float time(void(*sort)(std::vector<int>*, int), std::vector<int>* vector)
{

	std::chrono::duration<double, std::milli> time(0);
	int random = rand();
	auto start = std::chrono::steady_clock::now();
	sort(vector, random);
	auto end = std::chrono::steady_clock::now();
	time += (end - start);

	return time.count();
}