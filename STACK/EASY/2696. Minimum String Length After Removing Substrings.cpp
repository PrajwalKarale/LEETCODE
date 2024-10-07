/*
  Time Complexity:
    1. T.C -> O(n) where n is the length of string s
  Space Complexity:
    1. S.C -> O(n) since stack will contain all the letters of string s
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
};
class Solution {
public:
    int minLength(string s) {
        stack<char>st;
        for(char &ch: s){
            if(!st.empty()){
                if(st.top() == 'A' && ch == 'B'){
                    st.pop();
                    continue;
                }
                if(st.top() == 'C' && ch == 'D'){
                    st.pop();
                    continue;
                }
            }
            st.push(ch);
        }
        return st.size();
    }
};
