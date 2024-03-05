class Solution {
public:
    int minimumLength(string s) {
        // We will be using Two pointer approach.
        int i = 0;
        int j = s.length() - 1;
        //Since first and last character of the string should be equal then ony we can proceed
        while(i < j && s[i] == s[j]){
            char ch = s[i];
            // Now we are finding the prefix
            while(i < j && s[i] == ch){
                i += 1;
            }
            // Here we are finding the suffix
            while(j >= i && s[j] == ch){
                j -= 1;
            }
        }
        return j - i + 1;
    }
};
static int fastio = []() {
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();
