#include <iostream>
#include <cmath>

struct lcs {
    int length;
    std::string subsequence;
} hw1;

struct lcs memoStringLcs(const std::string a, const std::string b)   // O(mn)
{
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
    std::cout << memoStringLcs("hello", "ohell").length << '\n';
    std::cout << memoStringLcs("hello world", "ohell wxlxd").subsequence << '\n'; // 8
    std::cout << memoStringLcs("racecar", "racecar").length << '\n'; // 7
    std::cout << memoStringLcs("", "racecar").length << '\n'; // 0
}