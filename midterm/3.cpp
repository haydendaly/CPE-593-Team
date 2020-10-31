// I pledge my Honor that I have abided by the Stevens Honor System - Hayden C. Daly

#include<iostream>
#include<map>

using namespace std;

int findCollatzSeq(int n) {
    map<string, int> m;
    m["1"] = 1;
    int max_length = 1;
    int max_idx = 0;

    for (int i = 0; i < n; i++) {
        if (m.find(to_string(i)) == m.end()) {
            bool is_novel = true;
            int next_val = i;
            int length = 0;

            while (is_novel) {
                cout << next_val << '\n';
                if (next_val % 2 == 0) {
                    next_val = next_val / 2;
                } else {
                    next_val = 3*next_val + 1;
                }
                if (m.find(to_string(next_val)) != m.end()) {
                    int new_length = m[to_string(next_val)] + length;
                    if (new_length > max_length) {
                        max_length = new_length;
                        max_idx = i;
                    }
                    is_novel = false;
                    m[to_string(i)] = new_length;
                } else {
                    m[to_string(i)] = length;
                }
                length += 1;
            }
        }
    }
    return max_idx;
}

int main(int argc, char *argv[]) {
	int A = atoi(argv[1]);
    int max_idx = findCollatzSeq(A);

    cout << max_idx << '\n';
}