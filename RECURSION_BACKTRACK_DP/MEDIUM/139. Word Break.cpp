// T.C -> O(2^n) Because for every position we will break into substring or not into substring
// S.C -> O(301) Since we have create memoization array

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
    unordered_set<string>words;
    int t[301];
    bool solve(string s, unordered_set<string>&words, int index){
        if(t[index] != -1){
            return t[index];
        }
        if(index >= s.length()){
            return true;
        }
        if(words.find(s) != words.end()){
            return true;
        }
        // This is the length of the substring that is to be chosen starting from "index"
        for(int l = 1; l <= s.length(); l++){
            string temp = s.substr(index, l);
            if(words.find(temp) != words.end() && solve(s, words, index + l)){
                return t[index] = true;
            }
        }
        return t[index] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(t, -1, sizeof(t));
        for(string &word: wordDict){
            words.insert(word);
        }
        return solve(s,words,0);
    }
};
