/*LeetCode Problem 30: Substring with Concatenation of All Words.
Let’s go step by step so you understand it deeply, not just get the code.

📄 Problem Statement
You’re given:

A string s

A list of words words, all the same length

You need to:

Find all starting indices of substrings in s that are a concatenation of each word exactly once, in any order, without extra characters.*/

/*Input:
s = "barfoothefoobarman"
words = ["foo","bar"]

Output: [0, 9]

Explanation:
- "barfoo" starting at 0
- "foobar" starting at 9
*/

/*Input:
s = "wordgoodgoodgoodbestword"
words = ["word","good","best","word"]

Output: []
*/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty() || s.empty()) return result;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int substringLen = wordLen * wordCount;
        int n = s.size();

        unordered_map<string, int> wordMap;
        for (auto &w : words) wordMap[w]++;

        // Try different offsets
        for (int offset = 0; offset < wordLen; offset++) {
            unordered_map<string, int> seenMap;
            int left = offset, count = 0;

            for (int right = offset; right + wordLen <= n; right += wordLen) {
                string w = s.substr(right, wordLen);

                if (wordMap.count(w)) {
                    seenMap[w]++;
                    count++;

                    // If we have too many of this word, shrink from left
                    while (seenMap[w] > wordMap[w]) {
                        string leftWord = s.substr(left, wordLen);
                        seenMap[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    // If all words matched
                    if (count == wordCount) {
                        result.push_back(left);
                        // Slide window forward by removing one word
                        string leftWord = s.substr(left, wordLen);
                        seenMap[leftWord]--;
                        left += wordLen;
                        count--;
                    }
                } 
                else {
                    // Not a valid word: reset
                    seenMap.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }
        return result;
    }
};
