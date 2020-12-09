#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;
// Global dictionary to hold characters and keys
map<char, int> table;
map<int, char> rosetta; // Reverse of table

vector<int> lzw_encode(string data) {
    vector<int> result;
    int count = 0;
    for (char ch : data) {
        if (table.find(ch) == table.end()) {
            count++;
            table[ch] = count;
            rosetta[count] = ch;
        }
    }
    for (char ch : data) {
        int curr = table[ch];
        result.push_back(curr);
    }
    return result;
}

string lzw_decode(vector<int> encoded_data) {
    string result;
    for (int x : encoded_data) {
        result += rosetta[x];
    }
    return result;
}

int main() { 
    // Test string
    string data = "banana bandana hbdsfbhxzf hb cfbhxz chvxzh chshv csh hv ch hv chvhv"; 
    vector<int> encoded_data = lzw_encode(data); 
    string decoded_data = lzw_decode(encoded_data); 

    // Console stages
    cout << "Raw: \n" << data << endl; 
    cout << "\nTable:\n";
    for (auto it : table) {
        cout << it.first << ": " << it.second << endl;
    }
    cout << "\nEncoded Data:\n";
    for (int i : encoded_data) {
        cout << i << ", ";
    }
    cout << "\n\nDecoded:\n" << decoded_data << endl;
}