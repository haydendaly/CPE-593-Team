#include <iostream>

using namespace std;

long smallestMultiple(int divisibleTo) {

	int possibleSmallest = 1; // possible smallest positive integer as determined through loops
	int n = 1; // 1 - 20 incremented throughout loop
	int smallest = 0; // tracks overall smallest positive integer

	while (possibleSmallest > 0) {
		n=1;
		while ((possibleSmallest % n == 0) && (n <= divisibleTo)) { // current possible answer is divisible by some number(s) in 1 - 20
			
			if (n == divisibleTo) { // the number has been tested on 1 - 20 and passed all, this is our answer
				smallest = possibleSmallest;
				break;
			}
			
			n++; // haven't tested all of 1 - 20 yet
		}
		
		possibleSmallest++; // try the next smallest number until we find one that is divisible by all of 1 - 20

		if (smallest > 0) { // answer must not be 0
			break;
		}
	}
	return smallest;
}

int main() {
    cout << smallestMultiple(20) << endl;
}