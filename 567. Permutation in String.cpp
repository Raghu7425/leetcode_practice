/*567. Permutation in String*/
/*Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false*/

class Solution{
public:
    bool checkInclusion(string s1, string s2){

        int freq1[26]={0};
        int freq2[26]={0};


        for(char c: s1){
            freq1[c-'a']++;
        }

        for(int i=0; i<s1.size(); i++){
            freq2[s2[i]-'a']++;
        }
        if(isfregquencysame(freq1,freq2)){
            return true;
        }
        for(int i=s1.size(); i<s2.size();i++){
            freq2[s2[i]-'a']++;
            freq2[s2[i-s1.size()]]--;
            if(isfregquencysame(freq1,freq2)){
                return true;
            }
        }
        return false;

    }
    bool isfregquencysame(int freq1[], int freq2[]){
        for(int i=0; i<26;i++){
            if(freq1[i]!=freq2[i]){
                return false;
            }
            
        }
        return true;
    }
}