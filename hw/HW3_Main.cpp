#include <iostream>
#include <stdio.h>
#include <ctime>
#include <sys/time.h>

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
		if (i-start > 100) {  // "k" for very large array should be ~100
		partialQuickSort(arr, start, i-1);
		}
		if (end-i+1 > 100) { // saves time by leaving the rest for insertion sort
		partialQuickSort(arr, i+1, end);
		}
	}
	return arr;
}

int * mergeSort(int arr[], int left, int right) {
	// Perform sort here
    return arr;
}

int * heapSort(int arr[], int left, int right) {
	// Perform sort here
    return arr;
}


int main() {
	std::freopen("./input.txt", "r", stdin); // read from input.txt

	/* Read in the length & range of trial arrays and how many trials */
	int range;
	std::cin >> range; // reads input.txt values from std::cin
	int arrCount;
	std::cin >> arrCount;

	/* Create trial arrays */
	std::srand(std::time(0)); // initialize random number generator
	int knuthTrial[range] = {}, heapTrial[range] = {}, mergeTrial[range] = {};
	int x;
	for (int j=0; j<arrCount; j++) {
	std::cout << "========== Trial " << j+1 << " ==========" << std::endl;

		for (int i=0; i<range; i++) {
			x = (std::rand() % range); // generates random y within given range
			knuthTrial[i]=x;
			mergeTrial[i]=x;
			heapTrial[i]=x;
		}

		/* Sort trial arrays */
		for (auto it : knuthTrial) std::cout << it << " ";
		std::cout << std::endl;
		std::cout << "Knuth Optimized Quick Sort" << std::endl;
		partialQuickSort(knuthTrial, 0, range-1);
		insertionSort(knuthTrial, range);
		for (auto it : knuthTrial) std::cout << it << " ";
		std::cout << std::endl;
		std::cout << std::endl;

		for (auto it : mergeTrial) std::cout << it << " ";
		std::cout << std::endl;
		std::cout << "Merge Sort" << std::endl;
		mergeSort(mergeTrial, 0, range-1);
		for (auto it : mergeTrial) std::cout << it << " ";
		std::cout << std::endl;
		std::cout << std::endl;

		for (auto it : heapTrial) std::cout << it << " ";
		std::cout << std::endl;
		std::cout << "Heap Sort" << std::endl;
		heapSort(heapTrial, 0, range-1);
		for (auto it : heapTrial) std::cout << it << " ";
		std::cout << std::endl;
		std::cout << std::endl;
	}


	/* Read in the length and values of an array from stdin */
	int length;
	std::cin >> length;
	int knuthArr[length] = {}, heapArr[length] = {}, mergeArr[length] = {};
	int y;
	for (int i=0; i<length; i++) {
		std::cin >> y; // reads from input.txt
		knuthArr[i]=y;
		mergeArr[i]=y;
		heapArr[i]=y;
	}

	/* Sort the array passed in via stdin */
	std::cout << "============================" << std::endl;
	std::cout << "Input Array" << std::endl;
	for (auto it : knuthArr) std::cout << it << " ";
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Knuth Optimized Quick Sort" << std::endl;
	partialQuickSort(knuthArr, 0, length-1);
	insertionSort(knuthArr, length);
	for (auto it : knuthArr) std::cout << it << " ";
	std::cout << std::endl;

	std::cout << "Merge Sort" << std::endl;
	mergeSort(mergeArr, 0, length-1);
	for (auto it : mergeArr) std::cout << it << " ";
	std::cout << std::endl;

	std::cout << "Heap Sort" << std::endl;
	heapSort(heapArr, 0, length-1);
	for (auto it : heapArr) std::cout << it << " ";
	std::cout << std::endl;
	//std::cout << "============================" << std::endl;
	std::cout << std::endl;


	/* Create large trial arrays */
	int z, depth=1000000;
	for (int j=0; j<3; j++) {
	int knuthLarge[depth] = {}, heapLarge[depth] = {}, mergeLarge[depth] = {};
	std::cout << "========== Array Length " << depth << " ==========" << std::endl;

		for (int i=0; i<depth; i++) {
			z = (std::rand() % depth); // generates random y within given range
			knuthLarge[i]=z;
			mergeLarge[i]=z;
			heapLarge[i]=z;
		}

		/* Sort trial arrays */
		clock_t k_time = clock();
		partialQuickSort(knuthLarge, 0, range-1);
		insertionSort(knuthLarge, range);
		k_time = clock() - k_time;
		std::cout << "Running time for Knuth Optimized Quick Sort: " << (float)k_time/CLOCKS_PER_SEC << " seconds" << std::endl;
		std::cout << std::endl;

		clock_t m_time = clock();
		mergeSort(mergeLarge, 0, range-1);
		m_time = clock() - m_time;
		std::cout << "Running time for Merge Sort: " << (float)m_time/CLOCKS_PER_SEC << " seconds" << std::endl;
		std::cout << std::endl;

		clock_t h_time = clock();
		heapSort(heapLarge, 0, range-1);
		h_time = clock() - h_time;
		std::cout << "Running time for Heap Sort: " << (float)h_time/CLOCKS_PER_SEC << " seconds" << std::endl;
		std::cout << std::endl;

		depth *= 10; // increase depth by 10x
	}

	/* Benchmark times */
	//...
}