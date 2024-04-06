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
    int longestValidParentheses(string s) 
    {
        stack <int> st;
        st.push(-1);
        int substring_length = 0;
        if(s.length() == 0)
        {
            return substring_length;
        }
        if(s.length() == 1)
        {
            return substring_length;
        }
        else
        {
            for(int i = 0; i< s.length(); i++)
            {
                if(s[i] == '(')
                {
                    st.push(i);
                }
                else
                {
                    st.pop();
                    if(!st.empty())
                    {
                        substring_length = max(substring_length , i - st.top());
                    }
                    else
                    {
                        st.push(i);
                    }
                    
                }
            }
        }
        return substring_length;
    }
};
