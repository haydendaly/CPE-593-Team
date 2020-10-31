// I pledge my honor I have abided the Stevens Honor System. - Hayden C. Daly
#include <iostream>

using namespace std;

// Declaring global variables
bool isPrime[1000001];
// Numbers of primes below 1 million is 78498 so array of this size
long primeMemo[78500], primeCount = 0;

void improvedErastosthenes() {
    // Referenced this: https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html and course noptes
    // 0, 1, 2+2n = True
    isPrime[0] = isPrime[1] = true;
    for (int i = 4; i <= 1000001; i += 2)
        isPrime[i] = true;
    primeMemo[primeCount++] = 2;
    // Test Primality
    for (int i = 3; i <= 1001; i += 2) {
        if (!isPrime[i]) {
            primeMemo[primeCount++] = i;
            for (int j = i * i; j <= 1000001; j += i)
                isPrime[j] = true;
        }
    }
    for (int i = 1003; i <= 1000001; i += 2) {
        if (!isPrime[i])
            primeMemo[primeCount++] = i;
    }
}

bool isLeftRight(int n) {
    int exp = 10;
    while (exp < n) {
        if (isPrime[n % exp] || isPrime[n / exp])
            return false;
        exp = exp*10;
    }
    return true;
}

int leftRightPrimes() {
    int result = 0;
    // Memoize primes to reference global arr
    improvedErastosthenes();
    for (int i = 4; i < primeCount; i++) {
        if (isLeftRight(primeMemo[i]))
            result += primeMemo[i];
    }
    return result;
}

int main() {
    cout << leftRightPrimes() << '\n';
}