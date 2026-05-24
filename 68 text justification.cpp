/*
Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left-justified, and no extra space is inserted between words.

Note:

A word is defined as a character sequence consisting of non-space characters only.
Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
The input array words contains at least one word.
 

Example 1:

Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Example 2:

Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be", because the last line must be left-justified instead of fully-justified.
Note that the second line is also left-justified because it contains only one word.
Example 3:

Input: words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], maxWidth = 20
Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
 */

 #include<iostream>
 #include<string>
 #include<vector>
 using namespace std;


class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int idx = 0;

        while (idx < n) {
            // 1. determine how many words fit in this line
            int lineLen = words[idx].size(); // sum of word lengths in line
            int last = idx + 1;
            while (last < n && lineLen + 1 + words[last].size() <= maxWidth) {
                lineLen += 1 + words[last].size(); // 1 for the mandatory single space
                last++;
            }

            int wordCount = last - idx;
            string line;

            // 2. if this is the last line or only one word -> left-justify
            if (last == n || wordCount == 1) {
                // put words separated by single spaces
                for (int i = idx; i < last; ++i) {
                    line += words[i];
                    if (i != last - 1) line += ' ';
                }
                // pad the end with spaces
                line += string(maxWidth - line.size(), ' ');
            } else {
                // 3. fully justify: distribute spaces evenly
                int totalWordLen = 0;
                for (int i = idx; i < last; ++i) totalWordLen += words[i].size();
                int totalSpaces = maxWidth - totalWordLen;
                int slots = wordCount - 1;
                int base = totalSpaces / slots;
                int extra = totalSpaces % slots; // first 'extra' slots get +1

                for (int i = idx; i < last; ++i) {
                    line += words[i];
                    if (i != last - 1) {
                        int spacesToInsert = base + ( (i - idx) < extra ? 1 : 0 );
                        line += string(spacesToInsert, ' ');
                    }
                }
            }

            result.push_back(line);
            idx = last; // move to next line
        }
        return result;
    }
};
