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
    string makeGood(string s) {
        if(s.length() == 1){
            return s;
        }
        string ans = "";
        for(int i = 0; i < s.length(); i++){
            ans.push_back(s[i]);
            while((ans.size()) && (ans.back() == s[i + 1] + 32 || ans.back() == s[i + 1] - 32)){
                ans.pop_back();
                i++;
            }
        }
        return ans;
    }
};
