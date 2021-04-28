/*
2021-04-27
André Nordlund
anno1907
Datastrukturer och algoritmer DT046G
Labb 3
*/
#include "algoritms.h"
#include "generation.h"
#include "output.h"
#include "timer.h"
#include <iostream>
int main() {
	srand(time(NULL));
	
	auto random = [](int N) {std::vector<int>* data = randomValues(N); return data; };
	auto increasing = [](int N) {std::vector<int>* data = monotonicIncreasing(N); return data; };
	auto decreasing = [](int N) {std::vector<int>* data = monotonicDecreasing(N); return data; };
	auto constant = [](int N) {std::vector<int>* data = constantValue(N); return data; };

	std::vector<int>* test = primeNumbers(20);
	for (int i = 0; i < test->size(); i++) {
		std::cout << test->at(i) << std::endl;
	}

	return 0;
}