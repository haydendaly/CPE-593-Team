#include <iostream>
#include <string>

using namespace std;

string run_length_encode(string a) { // O(n)
    string result = "";
    int count;
    for (int i = 0; i < a.length(); i++) {
        count = 1;
        while (i < a.length() - 1 && a[i] == a[i + 1]) {
            count++;
            i++;
        }
        result.append(a[i]);
        result.append(to_string(count));
    }
    return result;
}

int main() {
    string test = "cdzhbvhdszbvhdxzvhdhhdhdhhhhhhh";
    cout << run_length_encode(test);
}