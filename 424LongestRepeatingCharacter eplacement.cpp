//424. Longest Repeating Character Replacement
/*You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.*/

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);  // Stores frequency of each uppercase letter in the window
        int left = 0, right = 0;  // Sliding window pointers
        int maxlen = 0;           // Maximum length of valid window found
        int maxcount = 0;         // Maximum frequency of any single character in the current window

        // Start expanding the window
        while (right < s.size()) {
            // Update the frequency of the current character
            freq[s[right] - 'A']++;

            // Update maxcount: the count of the most frequent character in the current window
            maxcount = max(maxcount, freq[s[right] - 'A']);

            // If the number of characters to replace exceeds k, shrink the window from the left
            if ((right - left + 1) - maxcount > k) {
                // Reduce the frequency of the character going out of the window
                freq[s[left] - 'A']--;
                left++; // Move the left pointer to the right
            }

            // Update the maximum length of a valid window
            maxlen = max(maxlen, right - left + 1);
            right++; // Expand the window from the right
        }

        return maxlen; // Return the length of the longest valid substring
    }
};
