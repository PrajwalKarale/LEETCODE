#pragma GCC optimize("Ofast", "inline", "fast-math", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")

static bool _ = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return false;
}();

class Solution {
public:
    int n;
    int solve(string s, int k, int previous, int current){
        if(current >= n){
            return 0;
        }
        int take = 0;
        if(previous == -1 || abs((s[previous] - 'a') - (s[current] - 'a')) <= k){
            take = 1 + solve(s,k, current, current + 1);
        }
        int skip = solve(s, k, previous, current + 1);
        return max(take, skip);
    }
    int longestIdealString(string s, int k) {
        n = s.length();
        return solve(s,k,-1,0);
    }
};
