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

bool contains(std::vector<std::string> d, std::string word) {
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
	//std::cout << "\n\n\n\n";
	contains(d, "cat");
	contains(d, "xylophone");
	contains(d, "helllllloooooooo");


	std::freopen("./boggle.dat", "r", stdin); // read from input.txt
	int size;
	std::cin >> size;
	char c;
	char inputArray[size][size];

	for (int i=0; i<size; i++) {
		for (int j=0; j<size; j++) {
			std::cin >> c; // reads from boggle.dat
			inputArray[i][j]=c;
		}
	}

	for (int i=0; i<size; i++) {
		for (int j=0; j<size; j++) {
			std::cout << inputArray[i][j] << " ";
		}
		std::cout << std::endl;
	}

	return 0; 
}

//boggle at 52:30 in lecture

/*
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <functional>

std::vector<std::string> create_dict(){
	std::vector<std::string> d; 
	std::ifstream in("dictionary.txt"); 
	std::string str;
	int n = str.length();
	char char_array[n + 1];
	while(std::getline(in, str)) {
		if (str.length() > 0)
				d.push_back(str);
				std::strcpy(char_array, str.c_str());
				for (int i = 0; i < n; i++)
					std::cout << char_array[i];
	}
	return d; 
}
*/