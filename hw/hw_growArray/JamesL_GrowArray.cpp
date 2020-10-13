/* I pledge my Honor that I have abided by the Stevens Honor System. James Lawrence. */

#include<iostream>
#include<cstring>

class GrowArray {

	private:

		int* data;
		int used;
		int capacity;

		void grow() { // O(n)
			//std::cout << "grow" << std::endl;
			capacity *= 2;
			data = new int[capacity];
		}


	public:

		GrowArray() { // O(1)
			data = new int[1];
			used = 0;
			capacity = 1;
		}

		~GrowArray() { // O(1)
			delete [] data;
		}

		void addEnd(int a) { // O(1)
			std::cout << "Add to end 1 - " << a << std::endl;

			for(int v=1; v<=a; v++) {

				if(used==capacity) {
					int* old = data;
					grow();

					for (int i=0; i<used; i++) {
						data[i] = old[i];
					}

					delete [] old;
				}

				data[used] = v;
				used++;

				//std::cout << "used: " << used << "  capacity: " << capacity << std::endl;
				//printArray();
			}
		}

		void addStart(int b) { // O(n)
			std::cout << "Add to start 1 - " << b << std::endl;

			for(int v=b; v>0; v--) {

				int* old = data;

				if(used==capacity) {
					grow();
				}
				else{ data = new int[capacity]; } // bug fix for failure to copy old into data. still unsure why.
				
				for (int i=0; i<used; i++) {
					data[i+1] = old[i];
				}
				
				data[0] = v;
				delete [] old;
				used++;

				//std::cout << "used: " << used << "  capacity: " << capacity << std::endl;
				//printArray();
			}
		}

		void insert(int b, int c) { // O(n)
			std::cout << "Insert 1 - " << b << " at " << c << std::endl;

			for(int v=b; v>0; v--) {

				int* old = data;
				
				if(used==capacity) {
					grow();
				}
				else{ data = new int[capacity]; } // bug fix for failure to copy old into data. still unsure why.

				for(int i=0; i<c; i++) {
					data[i] = old[i];
				}
				for(int i=c; i<used; i++) {
					data[i+1] = old[i];
				}

				data[c] = v;
				delete [] old;
				used++;

				//std::cout << "used: " << used << "  capacity: " << capacity << std::endl;
				//printArray();
			}
		}

		void removeEnd(int a) { // O(1)
			std::cout << "Remove from end " << a << std::endl;

			for(int n=0; n<a; n++) {

				int* old = data;
				capacity--;
				used--;
				data = new int[capacity];

				for (int i=0; i<used; i++){
					data[i] = old[i];
				}

				delete [] old;

				//std::cout << "used: " << used << "  capacity: " << capacity << std::endl;
			}
		}

		void removeStart(int b) { // O(n)
			std::cout << "Remove from start " << b << std::endl;

			for(int n=0; n<b; n++) {

				int* old = data;
				capacity--;
				used--;
				data = new int[capacity];

				for (int i=0; i<used; i++) {
					data[i] = old[i+1];
				}

				delete [] old;

				//std::cout << "used: " << used << "  capacity: " << capacity << std::endl;
			}
		}

		void printSum() { // O(n)
			int sum = 0;
			for (int i=0; i<used; i++) {
				sum += data[i];
			}

			std::cout << "Sum: " << sum << std::endl;
		}

		void printArray() {
			for (int i=0; i<used; i++) {
				std::cout << data[i] << " ";
			}
			std::cout << std::endl;
		}
};


int main(int argc, char *argv[]) {
	/* parse command line args */
	int A = atoi(argv[1]);
	int B = atoi(argv[2]);
	int C = atoi(argv[3]);

	/* create GrowArray object */
	GrowArray modifiableArray;

	/* run specified functions */
	modifiableArray.addEnd(A);
	//modifiableArray.printArray();

	modifiableArray.addStart(B);
	//modifiableArray.printArray();

	modifiableArray.insert(B, C);
	//modifiableArray.printArray();

	modifiableArray.removeEnd(A);
	//modifiableArray.printArray();

	modifiableArray.removeStart(B);
	//modifiableArray.printArray();

	modifiableArray.printSum();
}