#include <iostream>
#include <string>
#include <map>

using namespace std;

string lzw_encode(map<string, int> table, string data) {
    string s = "";
    char ch;
    while (there is still data) {
        ch = character input;
        if (s + ch in table) {
            s = s + ch;
        } else {
            encode s to output file;
            add s + ch to dictionary;
            s = ch;
        }
    }
    encode s to output file;
}

void lzw_decode(map<string, int> table, string encoded_data) { 
    prevcode = read in a code;
    decode/output prevcode;
    while (there is still data) {
        currcode = read in a code;
        entry = table[currcode];
        output entry;
        ch = entry[0];
        add ((translation of prevcode) + ch) to dictionary;
        prevcode = currcode;
    }
}

int main() { 
    // Create dictionary of all 256 characters
    map<string, int> table;
    for (int i = 0; i <= 255; i++) {
        string ch = "";
        ch += char(i);
        table[ch] = 1;
    }

    // Test string
    string data = "Hello there hell the their ello"; 
    string encoded_data = lzw_encode(table, data); 
    string decoded_data = lzw_decode(table, encoded_data); 

    // Console steps
    cout << "Raw: \n" << data << endl; 
    cout << "Encoded: \n" << encoded_data << endl; 
    cout << "Decoded: \n" << decoded_data << endl;
}