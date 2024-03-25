class Solution {
public:
    int maximumLengthSubstring(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int ans = 0;
        int n = s.length();
        for(int i = 0; i < n; i++){
            unordered_map<char,int>temp;
            int j;
            for(j = i; j < n; j++){
                temp[s[j]]++;
                if(temp[s[j]] > 2){
                    break;
                }
                ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};
