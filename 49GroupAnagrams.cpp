/*49. Group Anagrams
Given an array of strings strs, group the anagrams together. You can return the answer in any order.
Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]

Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Explanation:

There is no string in strs that can be rearranged to form "bat".
The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.
Example 2:

Input: strs = [""]

Output: [[""]]

Example 3:

Input: strs = ["a"]

Output: [["a"]]

 */


#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Create a hashmap where:
        // - key: sorted version of the word
        // - value: vector of all words that match that sorted key (i.e., anagrams)
        unordered_map<string, vector<string>> mp;

        // Iterate through each string in the input
        for (string s : strs) {
            string key = s;                 // Copy the original string
            sort(key.begin(), key.end());  // Sort the string to form the key
                                           // All anagrams will have the same sorted key
            mp[key].push_back(s);          // Group original string into corresponding anagram group
        }

        // Prepare the final result by collecting all grouped anagram vectors
        vector<vector<string>> result;

        for (auto& it : mp) {
            result.push_back(it.second); // Push the group (vector of anagrams) to the result
        }

        return result; // Return the grouped anagrams
    }
};
