/*647. Palindromic Substrings

Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

 

Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".*/

class Solution {
public:
    int countSubstrings(string s) {

        int count = 0;

        for(int i=0; i<s.length(); i++){            //iterate string completely 
        //count the odd palindromes 
            count+=countPalindromes(s,i,i);

        //count the even palindromes

            count+=countPalindromes(s,i,i+1);
        }

        return count;
        
    }


    int countPalindromes(string s, int left, int right){
        int count = 0;
        //find the palindrome and increment the count
        while(left>=0 && right < s.length() && s[right]==s[left]){
            count++;

            right++;
            left--;
        }
        return count;
    }
};