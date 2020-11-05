#include <iostream>

using namespace std;

long smallestMultiple(int divisibleTo) {
    bool found = false;
    int temp, i = 1;
    while (!found) {
        temp = i;
        for (int j = 1; j <= divisibleTo; j++) {
            if (temp % j == 0) temp = temp / j;
            else break;
            if (i == divisibleTo && temp == 1) {
                found = true;
            }
        }
        i += divisibleTo;
    }
    return temp;
}

int main() {
    cout << smallestMultiple(10) << '\n';
}