//Remove Consecutive Characters-gfg

/*You are given a string s, consisting of lowercase alphabets. 
Your task is to remove consecutive duplicate characters from the string. 

Example:

Input: s = "aabb"
Output:  "ab" 
Explanation: 
The character 'a' at index 2 is the same as 'a' at index 1, so it is removed.
Similarly, the character 'b' at index 4 is the same as 'b' at index 3, so it is removed.
The final string is "ab".

Input:s = "aabaa"
Output: "aba"
Explanation: 
The character 'a' at index 2 is the same as 'a' at index 1, so it is removed.
The character 'a' at index 5 is the same as 'a' at index 4, so it is removed.
The final string is "aba".

Input: s = "abcddcba"
Output: "abcdcba"
Explanation: 
The character 'd' at index 5 is the same as 'd' at index 4, so it is removed.
No other consecutive duplicates exist.
The final string is "abcdcba".*/

class Solution {
public:
    string removeConsecutiveCharacter(string& s) {
        if (s.empty()) return "";

        string result = "";
        result += s[0];  // Always keep the first character

        for (int i = 1; i < s.length(); i++) {
            if (s[i] != s[i - 1]) {
                result += s[i];
            }
        }

        return result;
    }
};

class Solution {
public:
    string removeConsecutiveCharacter(string& s) {
        int i = 0;
        while (i < s.length() - 1) {
            if (s[i] == s[i + 1]) {
                s.erase(i + 1, 1);  // Remove the duplicate
                // Don't increment i, because we need to recheck new s[i+1]
            } else {
                i++;  // Move to next character only if no deletion
            }
        }
        return s;
    }
};