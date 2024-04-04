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
    int maxDepth(string s) {
        int openBrackets = 0;
        int result = 0;
        for(char &c: s){
            if(c == '('){
                openBrackets++;
                result = max(result, openBrackets);
            }
            if(c == ')'){
                openBrackets--;
            }
        }
        return result;
    }
};
