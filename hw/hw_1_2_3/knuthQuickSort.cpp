#include <iostream>

/*
I pledge my honor I have abided by the Stevens Honor System.
- Hayden C. Daly, James Lawrence, Roman Bellisari
*/

int * insertionSort(int arr[], int n) {
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
    return arr;
}

int * partialQuickSort(int arr[], int start, int end) {
	
	if (start < end) {
		int pivot = (arr[start]+arr[end])/2;
		int i = start;
		int j = end;

		while (i < j) {
			while (arr[i] <  pivot) { i++; }
			while (arr[j] >= pivot) { j--; }

			if (i < j) { 
				std::swap(arr[i], arr[j]); 
			}
		}
		if (i-start > 3) {  // "k" for very large array should be ~200
		partialQuickSort(arr, start, i-1);
		}
		if (end-i+1 > 3) { // saves time by leaving the rest for insertion sort
		partialQuickSort(arr, i+1, end);
		}
	}
	return arr;
}

int main() {
    int arr[10] = {7, 1, 6, 4, 8, 5, 10, 2, 3, 9};
	partialQuickSort(arr, 0, 9);
	for (auto it : arr) std::cout << it << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;

    insertionSort(arr, 10);
    for (auto it : arr) std::cout << it << std::endl;
}