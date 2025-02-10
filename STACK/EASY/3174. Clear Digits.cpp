/*
    Logic:
        1. As soon as we are encountering the digit we have to delete the closest character which is in the left of the digit.
        2. So which means that we have to look everytime at the left whenever we see a digit so the appropriate data structure to be used is `stack`
    Time Complexity:
        1. T.C -> O(n) where n is the length of the string
    Space Complexity:
        1. We have used stack as an auxiliary space
        2. S.C -> O(n) where n is the length of the string
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    string clearDigits(string s) {
        string result = "";
        stack<char>st;
        for(char &c: s){
            if(isdigit(c)){
                st.pop();
            }else{
                st.push(c);
            }
        }
        while(!st.empty()){
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
