/*
    Time Complexity:
        T.C -> O(n) where n is the length of the expression
    Space Complexity:
        S.C -> O(n) since we have used the sxtack to store the characters from the string

*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    bool parseBoolExpr(string expression) {
        int n = expression.length();
        stack<char>st;
        for(int i = 0; i < n; i++){
            if(expression[i] == ','){
                continue;
            }else if(expression[i] == ')'){
                bool hasTrue = false;
                bool hasFalse = false;
                while(!st.empty() && st.top() != '('){
                    char topValue = st.top();
                    st.pop();
                    if(topValue == 't'){
                        hasTrue = true;
                    }
                    else if(topValue == 'f'){
                        hasFalse = true;
                    }
                }
                st.pop();
                char op = st.top();
                st.pop();
                if(op == '!'){
                    st.push(hasTrue == true ? 'f': 't');
                }
                else if(op == '&'){
                    st.push(hasFalse == true? 'f' : 't');
                }else{
                    st.push(hasTrue == true ? 't': 'f');
                }
            }else{
                st.push(expression[i]);
            }
        }
        return st.top() == 't' ? true : false;
    }
};
