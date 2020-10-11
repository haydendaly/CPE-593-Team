#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

typedef boost::multiprecision::cpp_int big;

big fact(big n) noexcept {
    if (n < 1) return 1;
    if (n % 10 == 0) return fact(n-1)*n/10;
    else return fact(n-1)*n;
}

big sumDigits(big n) {
    if (n < 10) return n;
    return n % 10 + sumDigits(n / 10);
}

int main() {
    std::cout << sumDigits(fact(100)) << '\n';
    return 1;
}
