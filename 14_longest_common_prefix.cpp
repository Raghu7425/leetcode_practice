//14. Longest Common Prefix
/*Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";

        string prefix=strs[0];

        for( int i=1;i<strs.size();i++){
            int j=0;

            while(j<prefix.size() && j<strs[i].size() && prefix[j]==strs[i][j]){    //madatory checks
                j++;
            }
            prefix=prefix.substr(0,j);

            if(prefix.size()==0) return "";                                         //mandatory for differnt strings



        }
        return prefix;
    }
};