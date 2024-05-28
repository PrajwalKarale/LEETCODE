/*
T.C -> The j pointer in the outer while loop is helping us to visit all the characters in the string.
In the worst case pointer i will also visit all the characters in the string. So the T.C is O(2*n)
S.C -> O(1)
*/
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
    int equalSubstring(string s, string t, int maxCost) {
        int i = 0;
        int j = 0;
        int cost = 0;
        int maxLength = 0;
        while(j < s.length()){
            cost = cost + (abs(t[j] - s[j]));
            while(cost > maxCost){
                cost = cost - abs(t[i] - s[i]);
                i += 1;
            }
            int length = j - i + 1;
            maxLength = max(maxLength, length);
            j++;
        }
        return maxLength;
    }
};
