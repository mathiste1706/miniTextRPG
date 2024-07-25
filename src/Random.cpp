#include "Random.hpp"

int randomNumberAdd(int lowerNumber, int upperNumber){
	int randomNumber=0;
	if (upperNumber!=0){
		srand(std::chrono::system_clock::now().time_since_epoch().count());
		randomNumber=lowerNumber+(rand()%upperNumber);
	}

	return randomNumber;
}

double randomNumberMultiply(double lowerNumber, double upperNumber){
	double randomNumber=0;
	if (upperNumber!=0){
		srand(std::chrono::system_clock::now().time_since_epoch().count());
		randomNumber=lowerNumber+(float)rand()/(float)(RAND_MAX/upperNumber);
	}

	return randomNumber;
}
