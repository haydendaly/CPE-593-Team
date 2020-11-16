#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <functional>

std::vector<std::string> create_dict(){
	std::vector<std::string> d; 
	std::ifstream in("dictionary.txt"); 
	std::string str; 
	while(std::getline(in, str)) {
		if (str.size() > 0)
				d.push_back(str); 
	}
	return d; 
}

void print_dict(std::vector<std::string> d ) {
	for (int i =0; i < d.size(); i++) {
		std::cout << d[i] << "\n"; 
	}
}

bool is_in_dict(std::vector<std::string> d, std::string word) {
	for (int i =0; i < d.size(); i++) {
		if( d[i] == word){
			std::cout << "'" << word << "'" << " found in dictionary - true \n";  
			return true;
		}
	}
	std::cout << "'" <<  word << "'" << " not found in dictionary - false \n"; 
	return false; 
}

int main() {
	std::vector<std::string> d = create_dict(); 
	//print_dict(d);
	std::cout << "\n\n\n\n"; 
	is_in_dict(d, "cat"); 
	is_in_dict(d, "helllllloooooooo");

	return 0; 
}

