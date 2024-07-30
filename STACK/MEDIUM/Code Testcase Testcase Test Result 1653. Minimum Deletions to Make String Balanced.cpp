/*
1. Stack Approach:
    T.C -> O(n) since we are traversing the Full String
    S.C - > O(n) since stack is being used
*/
class Solution {
public:
    int minimumDeletions(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int deletions = 0;
        stack<char>st;

        for(char &c: s){
            if(c == 'a'){
                if(!st.empty()){
                    st.pop();
                    deletions++;
                }
            }else{
                st.push(c);
            }
        }
        return deletions;
    }
};
