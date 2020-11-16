#include <iostream>
#include <fstream>
#include <functional>
#include <string>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

// A Trie node
struct Trie
{
	bool isLeaf;
	unordered_map<char, Trie*> map;
};

Trie* newNode()
{
	Trie* node = new Trie;
	node->isLeaf = false;

	return node;
}

void add(Trie*& head, char* str)
{
	if (head == nullptr) {
		head = newNode();
	}

	Trie* current = head;
	while (*str)
	{
		if (current->map.find(*str) == current->map.end()) { // create new node if path doesn't exist
			current->map[*str] = newNode();
		}

		current = current->map[*str]; // next node

		str++; // next character
	}

	current->isLeaf = true;
}

bool contains(Trie* head, char* str)
{
	if (head == nullptr) { // empty Trie
		return false;
	}

	Trie* current = head;
	while (*str) {
		current = current->map[*str]; // next node

		if (current == nullptr) {// end of path in Trie
			return false;
		}

		str++; // next character
	}

	// if current node is leaf, reached the end of string. return true
	return current->isLeaf;
}

int main()
{
	Trie* head = nullptr;

	ifstream in("dictionary.txt"); 
	string str; 
	while(getline(in, str)) {
		if (str.size() > 0) {
			char word[str.size()];
			std::transform(str.begin(), str.end(), str.begin(), ::tolower);
			strcpy(word, str.c_str());

			add(head, word);
		}
	}
	
	cout << contains(head, "hello") << " ";   			// print 1
	cout << contains(head, "helloOO") << " \n";   		// print 0
	cout << contains(head, "snap") << " ";   			// print 1
	cout << contains(head, "bat") << " \n";   			// print 1
	cout << contains(head, "xylophone") << " ";   		// print 1
	cout << contains(head, "xylophoneZZ") << " \n";   	// print 0
	cout << contains(head, "apple") << " ";		   		// print 1
	cout << contains(head, "appleOrange") << " \n";   		// print 0


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