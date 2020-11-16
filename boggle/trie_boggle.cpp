#include <iostream>
#include <fstream>
#include <functional>
#include <string>
#include <utility>      // std::pair
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

// A Trie node
struct Trie
{
	bool isLeaf;
	unordered_map<char, Trie*> myTrie;
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
		if (current->myTrie.find(*str) == current->myTrie.end()) { // create new node if path doesn't exist
			current->myTrie[*str] = newNode();
		}

		current = current->myTrie[*str]; // next node

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
		current = current->myTrie[*str]; // next node

		if (current == nullptr) {// end of path in Trie
			return false;
		}

		str++; // next character
	}

	// if current node is leaf, reached the end of string. return true
	return current->isLeaf;
}

bool containsPrefix(Trie* head, char* str)
{
	if (head == nullptr) { // empty Trie
		return false;
	}

	Trie* current = head;
	while (*str) {
		current = current->myTrie[*str]; // next node

		if (current == nullptr) {// end of path in Trie
			return false;
		}

		str++; // next character
	}

	// some word in Trie starts with given prefix
	return true;
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
	
	cout << contains(head, "hello") << " ";   				// print 1
	cout << contains(head, "helloOO") << " \n";   			// print 0
	cout << contains(head, "snap") << " ";   				// print 1
	cout << contains(head, "snappers") << " \n";   			// print 0
	cout << contains(head, "xylophone") << " ";   			// print 1
	cout << contains(head, "xylophoneZZ") << " \n";   		// print 0
	cout << contains(head, "apple") << " ";		   			// print 1
	cout << contains(head, "appleOrange") << " \n";   		// print 0

	cout << contains(head, "hel") << " ";   						// print 0
	cout << containsPrefix(head, "hel") << " \n";   				// print 1
	cout << contains(head, "sna") << " ";   						// print 0
	cout << containsPrefix(head, "sna") << " \n";   				// print 1
	cout << contains(head, "xylop") << " ";   						// print 0
	cout << containsPrefix(head, "xylop") << " \n";   				// print 1
	cout << contains(head, "appl") << " ";		   					// print 0
	cout << containsPrefix(head, "appl") << " \n";   				// print 1
	

	std::freopen("./boggle.dat", "r", stdin); // read from input.txt
	int size;
	std::cin >> size;
	char c;
	pair<char, bool> inputArray[size][size];

	for (int i=0; i<size; i++) {
		for (int j=0; j<size; j++) {
			std::cin >> c; // reads from boggle.dat
			inputArray[i][j]=make_pair(c, false);
		}
	}

	for (int i=0; i<size; i++) {
		for (int j=0; j<size; j++) {
			std::cout << "(" << inputArray[i][j].first << "," << inputArray[i][j].second << ") ";
		}
		std::cout << std::endl;
	}


	return 0;
}