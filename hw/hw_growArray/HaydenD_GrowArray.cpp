#include<iostream>
#include<cstring>

using namespace std;

class GrowArray {
	public:
		int* data;
		int amount;
		int capacity;
		void grow(int offset) { // O(n)
			int* temp = data;
			capacity *= 2;
			data = new int[capacity];
			for (int i = 0; i < amount; ++i) data[i + offset] = temp[i]; // O(n)
			delete[] temp;
		}
		void grow() { // O(n)
			grow(0);
		}
		GrowArray() { // Constructor O(1)
			amount = 0;
			capacity = 1;
			data = new int[capacity];
		}
		~GrowArray() { // Destructor O(1)
			delete[] data;
		}
		void addEnd(int a) { // O(1) amortized
			if (amount + 1 > capacity) grow();
			data[++amount] = a;
		}
		void addStart(int b) { // O(n)
			if (amount + 1 > capacity) grow(1);
			else {
				for (int i = amount - 1; i >= 0; --i) data[i+1] = data[i];
			}
			data[0] = b;
			++amount;
		}
		void insert(int b, int c) { // O(n)
			int* temp = data;
			if (amount + b > capacity) grow(b);
			for (int i = 0; i < c; ++i) data[i] = temp[i];
			for (int i = c; c < b + c; ++i) data[i] = b++;
			for (int i = c + b; i < amount; ++i) data[i] = temp[i - b];
			amount += b;
		}
		void removeEnd(int a) { // O(1)
			data[amount--] = 0;
		}
		void removeStart(int b) { // O(n)
			for (int i = 0; i < --amount; ++i) data[i] = data[i + 1]; // O(n)
		}
		void printSum() { // O(n)
			int sum = 0;
			for (int i = 0; i < amount; i++) // O(n)
				sum += data[i];
			cout << "Sum: " << sum << endl;
		}
		void viewArray() { // O(n)
			for (int i = 0; i < amount; i++) // O(n)
				cout << data[i] << " ";
			cout << endl;
		}
		int length() {
			return amount;
		}
};

int main(int argc, char *argv[]) {
	GrowArray example;
	example.addEnd(atoi(argv[1]));
	example.viewArray();
	example.addStart(atoi(argv[2]));
	example.viewArray();
	example.insert(atoi(argv[2]), atoi(argv[3]));
	example.viewArray();
	example.removeEnd(atoi(argv[1]));
	example.viewArray();
	example.removeStart(atoi(argv[2]));
	example.viewArray();
	example.printSum();
}