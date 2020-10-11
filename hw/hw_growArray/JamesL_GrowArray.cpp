/* I pledge my Honor that I have abided by the Stevens Honor System. James Lawrence. */

#include<iostream>
#include<cstring>

class BadGrowArray {

	private:
		int* data;
		int used; // if used == capacity --> grow
		int capacity;

	public:
		
		BadGrowArray() {

			/* initialize empty list (not preallocated) */
			this->data = nullptr;
			this->used = 0;
			this->capacity = 0;
		}

		~BadGrowArray() {

			/* release memory when object is out of scope */
			delete [] data;
		}

		void addEnd(int a) {
			std::cout << "Add to end 1 - " << a << std::endl;

			for(int v=1; v<=a; v++) {
				int* old = data;
				data = new int[capacity + 1];

				//memcpy(&data[0], &old[0], capacity);
				for (int i=0; i<capacity; i++) //O(n)
					data[i] = old[i];
				
				data[capacity] = v;
				delete [] old;
				capacity++;
			}
		}

		void addStart(int b) {
			std::cout << "Add to start 1 - " << b << std::endl;

			for(int v=b; v>0; v--) {
				int* old = data;
				data = new int[capacity + 1];

				//memcpy(&data[1], &old[0], capacity);
				for (int i=0; i<capacity; i++) //O(n)
					data[i+1] = old[i];
				
				data[0] = v;
				delete [] old;
				capacity++;
			}
		}

		void insert(int b, int c) {
			std::cout << "Insert 1 - " << b << " at " << c << std::endl;

			for(int v=b; v>0; v--) {
				int* old = data;
				data = new int[capacity + 1];

				//memcpy(&data[0], &old[0], c-1);
				//memcpy(&data[c+1], &old[c], capacity-c)
				for(int i=0; i<c; i++)
					data[i] = old[i];
				for(int i=c; i<capacity; i++)
					data[i+1] = old[i];

				data[c] = v;
				delete [] old;
				capacity++;
			}
		}

		void removeEnd(int a) {
			std::cout << "Remove from end " << a << std::endl;

		}

		void removeStart(int b) {
			std::cout << "Remove from start " << b << std::endl;
		}

		void printSum() {
			int sum = 0;
			std::cout << "Sum: " << sum << std::endl;

			for (int i=0; i<capacity; i++)
				std::cout << data[i] << " ";
		}

};


int main(int argc, char *argv[]) {
	/* parse command line args */
	int A = atoi(argv[1]);
	int B = atoi(argv[2]);
	int C = atoi(argv[3]);

	/* create GrowArray object */
	BadGrowArray modifiableArray;

	/* run specified functions */
	modifiableArray.addEnd(A);
	modifiableArray.addStart(B);
	modifiableArray.insert(B, C);
	modifiableArray.removeEnd(A);
	modifiableArray.removeStart(B);
	modifiableArray.printSum(); // !!!!!!!!!!!!!!!!!!!!!!!

}