#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b){
	return (a*b) / gcd(a,b);
}

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

int main(int argc, char *argv[]) {
	int a = atoi(argv[1]), b = atoi(argv[2]), r = atoi(argv[3]);
	
    std::cout << "GCD: " << gcd(a,b) << std::endl; 
    std::cout << "LCM: " << lcm(a,b) << std::endl;
    std::cout << "PMOD: " << powermod(a, b, r) << std::endl;
	
	//example: ./a.out 4 13 497
}