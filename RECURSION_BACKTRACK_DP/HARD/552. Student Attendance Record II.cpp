//T.C:
// For just recursion for each position we have 3 possibilities i.e P, A, L i.e O(3^n)
// With Memoisation: We are using a 3D array t[n][2][3] that means there are total n*2*3 distinct states. 
//This means that each distinct state is computed only once, and subsequent calls for the same state return the memoized value.
//Since there are at most n * 2 * 3 distinct states, and each state is computed only once, the overall time complexity is O(n * 2 * 3), which simplifies to O(n).
// S.C -> O(n)

#pragma clang attribute push (__attribute__((no_sanitize("address","undefined"))), apply_to=function)
#pragma clang attribute pop

class Solution {
public:
    int modulo = 1e9+7;
    int t[100001][2][3];
    int solve(int n, int absent, int consecutiveLate){
        if(absent > 1 || consecutiveLate >= 3){
            return 0;
        }
        if(n == 0){
            return 1;
        }
        if(t[n][absent][consecutiveLate] != -1){
            return t[n][absent][consecutiveLate];
        }
        int a = solve(n - 1, absent + 1, 0) % modulo;
        int cl = solve(n - 1, absent, consecutiveLate+1) % modulo;
        int p = solve(n - 1, absent, 0) % modulo;

        return t[n][absent][consecutiveLate] = (p + (a + cl)%modulo) % modulo;
    }
    int checkRecord(int n) {
        memset(t, -1, sizeof(t));
        //solve(input, number of days absent, number of consecutive late)
        return solve(n, 0, 0);
    }
};
