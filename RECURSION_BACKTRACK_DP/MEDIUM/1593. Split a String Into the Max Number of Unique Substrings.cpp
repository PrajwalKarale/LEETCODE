auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    void solve(string s, int i, int currentCount, unordered_set<string>&st, int &maxCount){
        // Pruning
        if(currentCount  + (s.length() - i) <= maxCount){
            return;
        }
        if(i >= s.length()){
            maxCount = max(maxCount, currentCount);
            return;
        }
        for(int j = i; j < s.length(); j++){
            string substring = s.substr(i, j - i + 1);
            if(st.find(substring) == st.end()){
                st.insert(substring);
                solve(s, j + 1, currentCount + 1, st, maxCount);
                st.erase(substring);
            }
        }
    }
    int maxUniqueSplit(string s) {
        unordered_set<string>st;
        int maxCount = 0;
        int currentCount = 0;
        int i = 0;
        solve(s, i, currentCount, st, maxCount);
        return maxCount;
    }
};
