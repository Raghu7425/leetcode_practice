/*3. Longest Substring Without Repeating Characters
Given a string s, find the length of the longest substring without duplicate characters.
Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.*/

#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen; // Set to store characters in the current window
        int n = s.size();         // Length of the input string
        int maxLength = 0;        // Stores the length of the longest substring found
        int left = 0, right = 0;  // Two pointers to define the sliding window

        // Loop until the right pointer reaches the end of the string
        while (right < n) {
            // If the character at index 'right' is not in the set, it's a unique character
            if (seen.find(s[right]) == seen.end()) {
                seen.insert(s[right]); // Add it to the set
                // Update the maximum length if this window is larger
                maxLength = max(maxLength, right - left + 1);
                right++; // Expand the window from the right
            } else {
                // If the character already exists in the set,
                // we remove the character at the left pointer
                seen.erase(s[left]);
                left++; // Shrink the window from the left
            }
        }

        return maxLength; // Return the length of the longest unique-character substring
    }
};
