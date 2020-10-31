#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std; 


/* 
bool usedAlready(char usedLettersArr[], char letter) {
    for(int i = 0; i < sizeof(usedLettersArr); i++) {
        if(letter == usedLettersArr[i]) {
            return true; 
        }
    }
    return false; 
}
*/ 
/* 
void uniqueSubset(std::string s){ // O(nlogn)
    char input[s.length() + 1]; 
    char usedLetters[] = {0}; 
    char output[] = {'0'};

    strcpy(input, s.c_str()); 
    cout << input << endl; 

    for (int i = 0; i < sizeof(input); i++) {
        //for testing, not currrently functional
        
        char tempChar[] = {'a', 'b', 'c'};
        bool temp = usedAlready(tempChar, 'c');
        cout << temp << endl; 
        

        if(usedAlready())

    }

    return;
}
*/ 
// ^^ Poor implementation, better usage with hash map

//Pesudocode
void uniqueSubset(string s){
    create empty hash map <letters, bool>
    create return char array, keep track of size of char array as maximum
    create temp char array, 

    for letter in string
        if letter does not exist in hash map (bool = false)
            add letter to hash map, set bool = true
            add letter to temp char array 
            if temp char array >= maximum char array (this is the return array)
                set temp char array to maximum char array
        
        move to next letter

    return maximum char array //or convert it to string and return string 
}



int main()
{
    uniqueSubset("Abracadabra");
    return 0;
}