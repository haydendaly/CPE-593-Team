#include <iostream>

int euler_2() {
	int n1 = 0; 
	int n2 = 1; 
	int sum = 0;
	int temp = 0;  

	while(n2 < 4000000) {
		if(n2 % 2 == 0) {
			sum += n2;
		}
		temp = n1 + n2; 
		n1 = n2; 
		n2 = temp;
	}
	return sum; 

}


int main() {
	std::cout << "Total: " << euler_2() << "\n"; 
	return 0; 
}