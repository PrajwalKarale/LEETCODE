class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>s_t;
        unordered_map<char,char>t_s;
        for(int i = 0; i < s.length(); i++){
            int ch1 = s[i];
            int ch2 = t[i];
            if((s_t.find(ch1) != s_t.end() && s_t[ch1] != ch2) || 
            (t_s.find(ch2) != t_s.end() && t_s[ch2] != ch1)){
                return false;
            }
            s_t[ch1] = ch2;
            t_s[ch2] = ch1;
        }
        return true;
    }
};
