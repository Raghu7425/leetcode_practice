/*🔢 LeetCode 10: Regular Expression Matching
Link: https://leetcode.com/problems/regular-expression-matching/

📄 Problem Statement:
Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

'.' matches any single character.

'*' matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).*/

/*Input: s = "aa", p = "a"
Output: false

Input: s = "aa", p = "a*"
Output: true

Input: s = "mississippi", p = "mis*is*p*."
Output: false
*/

class Solution {
public:
    int dp[21][31]; // dp[i][j] = result of match(s[i:], p[j:])

    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof(dp)); // -1 means not calculated
        return match(0, 0, s, p);
    }

    bool match(int i, int j, const string &s, const string &p) {
        if (dp[i][j] != -1) return dp[i][j]; // use stored result

        // ✅ base case: if pattern is finished
        if (j == p.length()) {
            return dp[i][j] = (i == s.length()); // true only if s is also finished
        }

        // Check if first character matches (or if pattern has '.')
        bool firstMatch = (i < s.length() &&
                          (s[i] == p[j] || p[j] == '.'));

        // 🟡 If next pattern char is '*'
        if (j + 1 < p.length() && p[j + 1] == '*') {
            // Try skipping '*' and current char, or using it if it matches
            dp[i][j] = (match(i, j + 2, s, p) ||
                        (firstMatch && match(i + 1, j, s, p)));
        } else {
            // Normal case: check next characters
            dp[i][j] = firstMatch && match(i + 1, j + 1, s, p);
        }

        return dp[i][j];
    }
};


