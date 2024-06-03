auto initialize = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0;
        int j = 0;
        while(i < s.length()){
            if(s[i] == t[j]){
                i++;
                j++;
            }else{
                i++;
            }
        }
        return t.length() - j;
    }
};
