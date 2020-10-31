// I pledge my honor I have abided the Stevens Honor System. - Hayden C. Daly
#include <iostream>

using namespace std;

uint64_t powermod(int base, int exp, int mod) {
    if (mod == 1) return 0;
    unsigned long long prod = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 != 1) prod = (prod * base) % mod;
        base = (base * base) % mod;
        exp = exp/2;
    }
    return prod;
}

uint64_t rando(int a, uint64_t b) {
    return a + rand() % ((b + 1) - a);
}

bool isSquared(uint64_t x) {
    uint32_t sqr = sqrt(x);
    return ((sqr - floor(sqr)) == 0);
}

// Could use Miller Rabin / SolovayStrassen but using fermat for time sake
bool isPrime(uint64_t p, int k) {
    for (int i = 0; i < k; i++) {
        uint64_t a = rando(2, p-1);
        if (powermod(a, p-1, p) != 1)
            return false;
    }
    return true;
}

uint64_t getPrimesSum(uint64_t a, uint64_t b) {
    uint64_t sum = 0;
    for (uint64_t i = a; i < b; i++) {
        if (i >= 20 && isSquared(i - 20) && isPrime(i, 1000))
            sum += i;
    }
    return sum;
}

int main(int argc, char *argv[]) {
    int A = atoi(argv[1]);
    int B = atoi(argv[2]);

    cout << getPrimesSum(A, B) << '\n';
}