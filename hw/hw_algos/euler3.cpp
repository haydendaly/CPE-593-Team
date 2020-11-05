#include <iostream>

using namespace std;

int largestPrimeFactor(long n) {
    long val = n;
    int factor;
    // For larger numbers, can use prime number sieve for more efficient time
    for (factor = 1; val != 1 && factor <= n; factor++) {
        if (val % factor == 0) val = val / factor;
    }
    return --factor;
}

int main() {
    cout << largestPrimeFactor(600851475143) << '\n';
}