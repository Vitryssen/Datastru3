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
	
	auto primes = [](int N) {std::vector<int>* data = primeNumbers(N); return data; };

	int start = 1000;
	int end = 10000;
	int increment = 1000;
	time_all(primes, start, end, increment);

	return 0;

	return 0;
}