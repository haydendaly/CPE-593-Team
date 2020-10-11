#include <iostream>

/*
I pledge my honor I have abided by the Stevens Honor System.
- Hayden C. Daly, James Lawrence, Roman Bellisari
*/

/* Struct to hold number of matching characters and string of all matching characters */
typedef struct {
    int length;
    std::string subsequence;
} lcs;

/* Function calculating LCS and identifying matching characters in O(m*n) time */
lcs memoStringLcs(const std::string a, const std::string b)
{
	lcs hw1;

    int memo[1000][1000] = {0};
    int i, j;
    int maxVal = 0;
    std::string ans = {};

    for (i = 1; i <= a.length(); i++) {
        for (j = 1; j <= b.length(); j++) {
            if (a[i - 1] == b[j - 1]) {
                memo[i][j] = memo[i-1][j-1] + 1;
                if (memo[i][j] > maxVal) {
                    maxVal++;
                    ans.push_back(b[j - 1]);
                }
            }
            else {
                memo[i][j] = std::max(memo[i][j-1], memo[i-1][j]);
            }
        }
    }

    hw1.length = memo[a.length()][b.length()];
    hw1.subsequence = ans;
    return hw1;
}

int main()
{
    std::cout << "hello, ohell:              " << "length: " << memoStringLcs("hello", "ohell").length << " subsequence: " << memoStringLcs("hello", "ohell").subsequence << std::endl; // 4
    std::cout << "hello world, ohell wxlxd:  " << "length: " << memoStringLcs("hello world", "ohell wxlxd").length << " subsequence: " << memoStringLcs("hello world", "ohell wxlxd").subsequence << std::endl; // 8
    std::cout << "racecar, racecar:          " << "length: " << memoStringLcs("racecar", "racecar").length << " subsequence: " << memoStringLcs("racecar", "racecar").subsequence << std::endl; // 7
    std::cout << ", racecar:                 " << "length: " << memoStringLcs("", "racecar").length << " subsequence: " << memoStringLcs("", "racecar").subsequence << std::endl; // 0
}