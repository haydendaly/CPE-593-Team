#include <iostream>

/*
I pledge my honor I have abided by the Stevens Honor System.
- Hayden C. Daly, James Lawrence, Roman Bellisari
*/

void insertionSort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
    }
    return;
}

int main() {
    int arr[10] = { 5, 6, 2, 4, 8, 10, 1, 3, 9, 0 };
    insertionSort(arr, 10);
    for (auto it : arr) std::cout << it << '\n';
}