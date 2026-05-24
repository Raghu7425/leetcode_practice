//Print all the duplicate characters in a string

/*Input: s = "geeksforgeeks"
Output: ['e', 4], ['g', 2], ['k', 2], ['s', 2]
Explanation: Characters e, g, k, and s appear more than once. Their counts are shown in order of first occurrence.

Input: s = "programming"
Output: ['r', 2], ['g', 2], ['m', 2]
Explanation: Only r, g, and m are duplicates. Output lists them with their counts.

Input: s = "mississippi"
Output: ['i', 4], ['s', 4], ['p', 2]
Explanation: Characters i, s, and p have multiple occurrences. The output reflects that with count and order preserved.*/

// C++ Code to print duplicate characters 
// and their counts using Hashing
#include <bits/stdc++.h>
using namespace std;

// Function to print duplicate characters with their count
void printDuplicates(string s) {

    // Hash map to store frequency of each character
    unordered_map<char, int> freq;

    // Count frequency of each character
    for (char c : s) {
        freq[c]++;
    }

    // Traverse the map and print characters with count > 1
    for (auto it : freq) {
        if (it.second > 1) {
            cout << "['" << it.first << "', " << it.second << "], ";
        }
    }
}

int main() {

    string s = "geeksforgeeks";

    printDuplicates(s);

    return 0;
}