#include<cctype>
#pragma GCC optimize("Ofast", "inline", "fast-math", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")

static bool _ = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return false;
}();

class Solution {
public:
    int numberOfSpecialChars(string word) {
        set<char>st;
        for(char &c: word){
            if(isupper(c)){
                st.insert(c);
            }
        }
        for(auto &it: st){
            cout << it << " ";
        }
        if(st.size() == 0){
            return 0;
        }
        int result = 0;
        for(char &c: word){
            char ch = c - 32;
            if(st.find(ch) != st.end()){
                result += 1;
                st.erase(ch);
            }
        }
        return result;
    }
};
