#include <iostream>

using namespace std;

int fibSum(int n) {
    int first = 1, second = 1, sum = 0, temp = 0;
    while (first <= n) {
        if (first % 2 == 0) sum += first;
        temp = first;
        first = second;
        second = temp + second;
    }
    return sum;
}

int main() {
    cout << fibSum(4000000) << '\n';
}
