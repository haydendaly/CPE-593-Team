#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(){
    std::cout << "GCD: " << gcd(36,60) << '\n'; 
}