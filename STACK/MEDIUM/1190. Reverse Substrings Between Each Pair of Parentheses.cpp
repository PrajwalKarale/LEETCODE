class Solution {
public:
    string reverseParentheses(string s) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        string result;
        stack<char>st;

        for(char &c: s){
           if(c == ')'){
                string r = "";
                while(!st.empty() && st.top() != '('){
                    r = r + st.top();
                    st.pop();
                }
                if(!st.empty()){
                    st.pop();
                }
                for(char &c: r){
                    st.push(c);
                }
           }else{
            st.push(c);
           } 
        }
        while(!st.empty()){
            result = result + st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
