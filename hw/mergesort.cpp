#include <iostream>

/*
I pledge my honor I have abided by the Stevens Honor System.
- Hayden C. Daly, James Lawrence, Roman Bellisari
*/

void merge(int arr[], int left, int mid, int right) {
    int tempArr[right - left];
    int i = left, j = mid + 1, k = 0;
    while (i <= mid || j < right) {
        if (j == right || (i <= mid && arr[i] <= arr[j]))
            tempArr[k++] = arr[i++];
        else tempArr[k++] = arr[j++];
    }
    for (; k >= 0; k--) arr[left + k] = tempArr[k];
    return;
}

void mergesort(int arr[], int left, int right) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    mergesort(arr, left, mid);
    mergesort(arr, mid+1, right);
    merge(arr, left, mid, right);
    return;
}

int main() {
    int arr[10] = { 5, 6, 2, 4, 8, 10, 1, 3, 9, 0 };
    mergesort(arr, 0, 9);
    for (auto it : arr) std::cout << it << '\n';
}