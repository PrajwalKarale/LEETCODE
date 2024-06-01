#pragma clang attribute push (__attribute__((no_sanitize("address","undefined"))), apply_to=function)
#pragma clang attribute pop

auto initialize = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int scoreOfString(string s) {
        int score = 0;
        for(int i = 0; i < s.length() - 1; i++){
            score  = score + abs(s[i] - s[i + 1]);
        }
        return score;
    }
};
