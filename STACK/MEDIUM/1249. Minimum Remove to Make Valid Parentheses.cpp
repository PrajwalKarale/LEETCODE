#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

auto initialize = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        stack<int> st;
        unordered_set<int>indexToBeRemoved;
        string result = "";

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                st.push(i);
            }else if(s[i] == ')'){
                if(st.empty()){
                    cout << i << endl;
                    indexToBeRemoved.insert(i);
                }else{
                    st.pop();
                }
            }
        }

        //Condition only if open brackets '(' are present
        while(!st.empty()){
            indexToBeRemoved.insert(st.top());
            st.pop();
        }

        for(int i = 0; i < n; i++){
            if(indexToBeRemoved.find(i) == indexToBeRemoved.end()){
                result.push_back(s[i]);
            }
        }
        return result;
    }
};
