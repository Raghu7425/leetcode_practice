//20. Valid Parentheses
/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

Example 5:

Input: s = "([)]"

Output: false*/

class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        
        for(int i=0;i<s.length();i++){

            char c = s[i];

            if((c=='(') || (c=='[') || (c=='{')){           //for single charecter use single quotes ''
                
                    st.push(c);
            }else{

                if(st.empty()) return false;            //mandatory check it shows first is ] or ) or ]

                char top= st.top();

                if((top=='(' && c==')') || (top=='[' && c==']') ||
                (top=='{' && c=='}') ){
                    st.pop();
                }else{
                    return false;
                }
            }
        }
        return st.empty();                          //check if stack is empty
    }
};