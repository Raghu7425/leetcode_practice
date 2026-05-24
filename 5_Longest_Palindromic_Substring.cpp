/*5. Longest Palindromic Substring

Given a string s, return the longest palindromic substring in s.

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.


Example 2:

Input: s = "cbbd"
Output: "bb"*/




class Solution {
public:
    // Function to expand around a center and return the palindrome substring
    string expandAroundCenter(string s, int left, int right) {
        // Expand while characters at left and right are the same
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;    // Move left one step to the left
            right++;   // Move right one step to the right
        }
        // Substring from left+1 to right-1 is the valid palindrome
        return s.substr(left + 1, right - left - 1);
    }

    string longestPalindrome(string s) {
        string longest = ""; // Store the longest palindrome

        // Go through every character as the center
        for (int i = 0; i < s.size(); i++) {
            // Odd-length palindrome (center at i)
            string oddPal = expandAroundCenter(s, i, i);

            // Even-length palindrome (center between i and i+1)
            string evenPal = expandAroundCenter(s, i, i + 1);

            // Choose the longer one
            if (oddPal.size() > longest.size()) longest = oddPal;
            if (evenPal.size() > longest.size()) longest = evenPal;
        }

        return longest;
    }
};
