#include <iostream>
#include <stdio.h>
#include <ctime>
#include <sys/time.h>
#include <math.h>	/* log10 */

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

int * mergeSort(int arr[], int left, int right) {
    if (left >= right) return arr;
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
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
	//int knuthTrial[range] = {}, heapTrial[range] = {}, mergeTrial[range] = {};
	int x;
	for (int j=0; j<arrCount; j++) {
		int *knuthTrial = new int[range];
		int *mergeTrial = new int[range];
		int *heapTrial = new int[range];
		std::cout << "========== Trial " << j+1 << " ==========" << std::endl;

		for (int i=0; i<range; i++) {
			x = (std::rand() % range); // generates random y within given range
			knuthTrial[i]=x;
			mergeTrial[i]=x;
			heapTrial[i]=x;
		}

		/* Sort trial arrays */
		for (int i=0; i<range; i++) std::cout << knuthTrial[i] << " ";
		std::cout << std::endl;
		std::cout << "Knuth Optimized Quick Sort" << std::endl;
		partialQuickSort(knuthTrial, 0, range-1);
		insertionSort(knuthTrial, range);
		for (int i=0; i<range; i++) std::cout << knuthTrial[i] << " ";
		std::cout << std::endl;
		std::cout << std::endl;

		for (int i=0; i<range; i++) std::cout << mergeTrial[i] << " ";
		std::cout << std::endl;
		std::cout << "Merge Sort" << std::endl;
		mergeSort(mergeTrial, 0, range-1);
		for (int i=0; i<range; i++) std::cout << mergeTrial[i] << " ";
		std::cout << std::endl;
		std::cout << std::endl;

		for (int i=0; i<range; i++) std::cout << heapTrial[i] << " ";
		std::cout << std::endl;
		std::cout << "Heap Sort" << std::endl;
		heapSort(heapTrial, 0, range-1);
		for (int i=0; i<range; i++) std::cout << heapTrial[i] << " ";
		std::cout << std::endl;
		std::cout << std::endl;

		delete[] knuthTrial; // release memory for new array
		delete[] heapTrial;
		delete[] mergeTrial;
	}


	/* Read in the length and values of an array from stdin */
	int length;
	std::cin >> length;
	//int knuthArr[length] = {}, heapArr[length] = {}, mergeArr[length] = {};
	int *knuthArr = new int[length];
	int *mergeArr = new int[length];
	int *heapArr = new int[length];
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
	for (int i=0; i<range; i++) std::cout << knuthArr[i] << " ";
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Knuth Optimized Quick Sort" << std::endl;
	partialQuickSort(knuthArr, 0, length-1);
	insertionSort(knuthArr, length);
	for (int i=0; i<range; i++) std::cout << knuthArr[i] << " ";
	std::cout << std::endl;

	std::cout << "Merge Sort" << std::endl;
	mergeSort(mergeArr, 0, length-1);
	for (int i=0; i<range; i++) std::cout << mergeArr[i] << " ";
	std::cout << std::endl;

	std::cout << "Heap Sort" << std::endl;
	heapSort(heapArr, 0, length-1);
	for (int i=0; i<range; i++) std::cout << heapArr[i] << " ";
	std::cout << std::endl;
	//std::cout << "============================" << std::endl;
	std::cout << std::endl;

	delete[] knuthArr; // release memory for new array
	delete[] heapArr;
	delete[] mergeArr;


	/* Create large trial arrays */
	int z, depth=1000000;
	//int * knuthLarge, * heapLarge, * mergeLarge;
	for (int j=0; j<3; j++) {
		int *knuthLarge = new int[depth];
		int *mergeLarge = new int[depth];
		int *heapLarge = new int[depth];
		std::cout << "======== Array Length 10^" << log10(depth) << " ========" << std::endl;

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

			delete[] knuthLarge; // release memory for new array
			delete[] heapLarge;
			delete[] mergeLarge;

			depth *= 10; // increase depth by 10x
	}

	/* ---Benchmark times--- 
	======== Array Length 10^6 ========
	Running time for Knuth Optimized Quick Sort: 5e-06 seconds

	Running time for Merge Sort: 8e-06 seconds

	Running time for Heap Sort: **???????????????????** seconds  ***add this when head sort uploaded!***

	======== Array Length 10^7 ========
	Running time for Knuth Optimized Quick Sort: 4e-06 seconds

	Running time for Merge Sort: 6e-06 seconds

	Running time for Heap Sort: **!!???????????????????!!** seconds  ***add this when head sort uploaded!***

	======== Array Length 10^8 ========
	// **errors allocating 10^8 length arrays because of RAM constraints**
	// . . .
	// . . .
	// . . .
	*/
}