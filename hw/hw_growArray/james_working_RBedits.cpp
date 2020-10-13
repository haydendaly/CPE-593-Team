/* I pledge my Honor that I have abided by the Stevens Honor System. James Lawrence. */

#include<iostream>
#include<cstring>

class BadGrowArray {

	public:
		int* data;
		int used; // if used == capacity --> grow
		int capacity;

		void grow() {
			/* grow the capacity by doubling */

			//if(capacity < 100) { // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			//	int* old = data;

				capacity *= 2;
				data = new int[capacity];

			//	for (int i=0; i<used; i++) //O(n)
			//		data[i] = old[i];
			//}
		}

		BadGrowArray() {
			/* initialize empty list (not preallocated) */
			data = new int[1];
			used = 0;
			capacity = 1;
		}



		~BadGrowArray() {
			/* release memory when object is out of scope */
			delete [] data;
		}

		void addEnd(int a) {
			std::cout << "Add to end 1 - " << a << std::endl;

			for(int v=1; v<=a; v++) {
				int* old = data;
				
				/*
				for (int i=0; i<used; i++) // O(n)
					std::cout << old[i] << " ";
				std::cout << std::endl;
				*/
				std::cout << "used: " << used << "  capacity: " << capacity << std::endl;				
				if(used == capacity) {

					grow();
				}

				for (int i=0; i<used; i++) //O(n)
					data[i] = old[i];
				
				/*
				for (int i=0; i<used; i++) // O(n)
					std::cout << data[i] << " ";
				std::cout << std::endl;				
				
				if(used == 0) {	data[0] = 1; }
				else if (used == 1) { data[1] = 2;}
				else { }
*/

				data[used] = v;
		//		delete [] old;
				used++;
			}

			/*
				for (int i=0; i<used; i++) // O(n)
					std::cout << data[i] << " ";
				std::cout << std::endl;
			*/
		}

		void addStart(int b) {
			std::cout << "Add to start 1 - " << b << std::endl;

			for(int v=b; v>0; v--) {
				int* old = data;

				if(used == capacity) {
					std::cout << "used: " << used << "  capacity: " << capacity << std::endl;
					grow();
				}
				//std::cout<< "used: " << used << " \n"; 
				for (int i=used -1; i >= 0; i--) //O(n)
					data[i+1] = old[i];
				
				data[0] = v;
			//	delete [] old;
				used++;
			}
		}

		void insert(int b, int c) {
			std::cout << "Insert 1-" << b << " at " << c << std::endl;

			//for(int v=b; v>0; v--) {
				int* old = data;
				
				
				while(used+b>capacity){
					//if(used == capacity) {
						std::cout << "used: " << used << "  capacity: " << capacity << std::endl;
						grow();
					//}
				}

				for(int i=0; i<c; i++)
					data[i] = old[i];
				int count = 1;
				for(int i = c; i < b+c; i++) { 
					data[i] = count;
					count++;
					std::cout <<"here \n";
				}

				for(int i = c+b; i < used + b; i++)
					data[i] = old[i-b];
				
				used = used + b;



/*
				for(int i=c; i<used; i++)
					data[i+1] = old[i];
*/
//				data[c] = v;
			//	delete [] old;
				//used++;
			//}
		}

		void removeEnd(int a) {
			std::cout << "Remove from end " << a << std::endl;

			for(int n=0; n<a; n++) {
				int* old = data;
				capacity--;
				used--;
				data = new int[capacity];

				//memcpy(&data[0], &old[0], used);
				for (int i=0; i<used; i++) //O(n)
					data[i] = old[i];

				delete [] old;
			}
		}

		void removeStart(int b) {
			std::cout << "Remove from start " << b << std::endl;

			for(int n=0; n<b; n++) {
				int* old = data;
				capacity--;
				used--;
				data = new int[capacity];

				//memcpy(&data[0], &old[1], used);
				for (int i=0; i<used; i++) //O(n)
					data[i] = old[i+1];

				delete [] old;
			}
		}

		void printSum() { // O(n)
			int sum = 0;
			for (int i=0; i<used; i++) // O(n)
				sum += data[i];

			std::cout << "Sum: " << sum << std::endl;
		}

		void viewArray() { // O(n)
			//std::cout << std::endl;
			//std::cout << "used: " << used << "  capacity: " << capacity << "  ";

			for (int i=0; i<used; i++) // O(n)
				std::cout << data[i] << " ";
			std::cout << std::endl;
		}

};


int main(int argc, char *argv[]) {
	/* parse command line args */
	int A = atoi(argv[1]);
	int B = atoi(argv[2]);
	int C = atoi(argv[3]);

	/* create GrowArray object */
	std::cout << A << ", " << B << ", " << C << std::endl;
	BadGrowArray modifiableArray;

	/* run specified functions */
	modifiableArray.addEnd(A);
	modifiableArray.viewArray();

	modifiableArray.addStart(B);
	modifiableArray.viewArray();

	modifiableArray.insert(B, C);
	modifiableArray.viewArray();	

	modifiableArray.removeEnd(A);
	modifiableArray.viewArray();

	modifiableArray.removeStart(B);
	modifiableArray.viewArray();

	modifiableArray.printSum();
/**/
}
