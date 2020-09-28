#include <iostream>

/*
I pledge my honor I have abided by the Stevens Honor System.
- Hayden C. Daly, James Lawrence, Roman Bellisari
*/

void merge(int arr[], int left, int mid, int right) {
    int tempArr[right - left + 1];
    int i = left, j = mid + 1, k = 0;

    while(i <= mid || j <= right) {
        if(i <= mid && (j > right || arr[i] <= arr[j]))
            tempArr[k++] = arr[i++];
        else
            tempArr[k++] = arr[j++];
    }

    for (int k = 0; k <= right - left; k++) 
        arr[left + k] = tempArr[k];
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
    int arr[10] = { 5, 6, 2, 4, 8, 10, 1, 3, 9, 7 };
    mergesort(arr, 0, 9);
    for (auto it : arr) std::cout << it << '\n';
}