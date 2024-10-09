/*
    Time Complexity:
        1.  We are tarversing the whole string s whose maximum length is 1000
        2. T.C -> O(1000)
    Space Complexity:
        1. We are using stack to store the opening brackets
        2. S.C -> O(n) where n is the number of openeing brackets in string s
*/
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int unbalanced = 0;
        for(char &ch: s){
            if(ch == '('){
                st.push(ch);
            }else if(ch == ')' && !st.empty()){
                st.pop();
            }else if(ch == ')' && st.empty()){
                unbalanced++;
            }
        }
        return st.size() + unbalanced;
    }
};
