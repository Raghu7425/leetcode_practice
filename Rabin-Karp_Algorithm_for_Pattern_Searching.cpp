
/*Rabin-Karp Algorithm for Pattern Searching
Last Updated : 25 Jul, 2025
Given two strings txt (the text) and pat (the pattern), consisting of lowercase English alphabets, find all 0-based starting indices where pat occurs as a substring in txt.*/


#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int mod = 1e9 + 7;
const int base = 31;

// Modular addition to keep
// values within mod
int add(int a, int b) {
    a += b;
    if (a >= mod) a -= mod;
    return a;
}

// Modular subtraction to prevent 
// negative values
int sub(int a, int b) {
    a -= b;
    if (a < 0) a += mod;
    return a;
}

// Modular multiplication for safe base exponentiation
int mul(int a, int b) {
    return (int)((1LL * a * b) % mod);
}

// Convert character to numeric value 
// ('a' = 1, ..., 'z' = 26)
int charToInt(char c) {
    return c - 'a' + 1;
}

// Precomputes prefix hashes and powers for the string
void computeHash(string &s, vector<int> &hash, vector<int> &power) {
    int n = s.size();
    hash.resize(n);
    power.resize(n);

    // Initialize hash and power for 
    // the first character
    hash[0] = charToInt(s[0]);
    power[0] = 1;

    // Build hash and power arrays using 
    // rolling hash technique
    for (int i = 1; i < n; i++) {
        hash[i] = 
            add(mul(hash[i - 1], base), charToInt(s[i]));
        power[i] = 
            mul(power[i - 1], base);
    }
}

// Retrieves hash of substring s[l...r] in O(1)
int getSubHash(int l, int r, 
            vector<int> &hash, vector<int> &power) {
    int h = hash[r];
    if (l > 0) {
        
        // Subtract prefix hash to isolate [l...r]
        h = sub(h, mul(hash[l - 1], power[r - l + 1]));
    }
    return h;
}

// Rabin-Karp function to find all pattern 
// matches in text
vector<int> rabinKarp(string &text, 
                                string &pattern) {
    int n = text.size(), m = pattern.size();
    vector<int> hashText, powerText;
    computeHash(text, hashText, powerText);

    vector<int> hashPat, powerPat;
    computeHash(pattern, hashPat, powerPat);
    // Full pattern hash
    int patternHash = hashPat[m - 1];  

    vector<int> result;

    // Slide a window and compare text hash with pattern hash
    for (int i = 0; i <= n - m; i++) {
        int currentHash = getSubHash(i, i + m - 1, 
                                    hashText, powerText);

        // If hash matches, add the index to result
        if (currentHash == patternHash) {
            result.push_back(i);
        }
    }

    return result;
}

int main() {
    string txt = "geeksforgeeks";
    string pat = "geek";

    vector<int> positions = 
                rabinKarp(txt, pat);
    for (int idx : positions) {
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}