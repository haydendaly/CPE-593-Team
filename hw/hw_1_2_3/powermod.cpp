#include <iostream>

int powermod(int base, int exp, int mod) {
    if (mod == 1) return 0;
    int prod = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp&1) prod = (prod * base) % mod;
        base = (base * base) % mod;
        exp = exp/2;
    }
    return prod;
}

int main() {
    std::cout << powermod(4, 13, 497) << '\n';
}