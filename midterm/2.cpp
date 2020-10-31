// I pledge my Honor that I have abided by the Stevens Honor System - Hayden C. Daly

#include<iostream>
#include <math.h>

using namespace std;

unsigned long long powermod(int base, int exp, int mod) {
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

unsigned long long computeLastDigits(int factor, int base, int exp, int digits) {
    unsigned long long result = (factor * powermod(base, exp, digits)) + 1;
    return result;
}

int main(int argc, char *argv[]) {
    // 28433, 2, 7830457, 10
	int factor = atoi(argv[1]);
    int base = atoi(argv[2]);
	int exp = atoi(argv[3]);
	int digits = atoi(argv[4]);
    unsigned long long result = computeLastDigits(factor, base, exp, pow(10, digits));

    cout << result << '\n';
}