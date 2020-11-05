#include <iostream>

using namespace std;

bool isPalindrome(int original) {
    int forward = original, reverse = 0;
    while (forward > 0) {
        int last = forward % 10;
        reverse = reverse * 10 + last;
        forward = forward / 10;
    }
    return original == reverse;
}

int largestPalindrome(int maxDigit) {
    int largestPalindrome = 0;
    for (int a = 1; a <= maxDigit; a++) {
        for (int b = 1; b <= maxDigit; b++) {
            if (a * b >= largestPalindrome && isPalindrome(a * b))
                largestPalindrome = a * b;
        }
    }
    return largestPalindrome;
}

int main() {
    cout << largestPalindrome(999) << '\n';
}