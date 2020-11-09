#include <iostream>

int reverseNum(int num) {
	int remainder, lastNum, answer = 0;

	while (num != 0) {
		remainder = num%10;
		lastNum = remainder;
		answer = answer*10 + remainder;
		num /= 10;
	}

	if (answer%10 == lastNum) {
		return answer;
	}
	else {
		return 0;
	}

}

int main() {
	std::cout << "Overflow:    Reverse 1234567899 = " << reverseNum(1234567899) << std::endl;
	std::cout << "No overflow: Reverse 123456789  = " << reverseNum(123456789) << std::endl;
}