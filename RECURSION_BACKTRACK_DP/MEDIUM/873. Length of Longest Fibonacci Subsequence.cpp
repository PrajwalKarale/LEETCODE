/*
 * @lc app=leetcode id=873 lang=cpp
 *
 * [873] Length of Longest Fibonacci Subsequence
*/
// @lc code=start
/*
    Logic:
        1. When we read the question we can see that there can be multiple sequences due to which we can understand that there may be multiple solutions.
        2. Wherever we have options our first approach that comes in my mind is recursion. if there are three numbers a(i),b(j),c(k) and c = a + b where i, j , k are indices of a,b,c respectively
        then we know that i < j < k. So we need to iterate over `arr` using two for loops that will help us to find a from c and b since a = c - b.
        3. State Definition -> dp[i][j] -> Maximum Length of the fibonacci sequence ending at [i][j].
    Time Complexity:
        1. T.C -> O(n^2)
    Space Complexity:
        1. S.C -> O(n^2)
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    int solve(int j, int k, vector<int>&arr, unordered_map<int,int>&eleIndex){
        int target = arr[k] - arr[j];
        if(eleIndex.count(target) && eleIndex[target] < j){
            int i = eleIndex[target];
            return solve(i, j, arr, eleIndex) + 1;
        }
        return 2;
    }
    int recursion(vector<int>&arr){
        int n = arr.size();
        unordered_map<int,int>eleIndex;
        int result = INT_MIN;
        for(int i = 0; i < n; i++){
            eleIndex[arr[i]] = i;
        }
        for(int j = 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                int length = solve(j, k, arr, eleIndex);
                if(length >= 3){
                    result = max(result, length);
                }
            }
        }
        return result;
    }
    int memoize(int j, int k, vector<int>&arr, unordered_map<int,int>&eleIndex, vector<vector<int>>&dp){
        if(dp[j][k] != -1){
            return dp[j][k];
        }
        int target = arr[k] - arr[j];
        if(eleIndex.count(target) && eleIndex[target] < j){
            int i = eleIndex[target];
            return dp[j][k] = memoize(i, j, arr, eleIndex, dp) + 1;
        }
        return dp[j][k] = 2;
    }
    int memoization(vector<int>&arr){
        int n = arr.size();
        unordered_map<int,int>eleIndex;
        vector<vector<int>>dp(n, vector<int>(n, -1));
        int result = 0;
        for(int i = 0; i < n; i++){
            eleIndex[arr[i]] = i;
        }
        for(int j = 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                int length = memoize(j, k, arr, eleIndex, dp);
                if(length >= 3){
                    result = max(result, length);
                }
            }
        }
        return result;
    }
    int tabulation(vector<int>&arr){
        int n = arr.size();
        vector<vector<int>>dp(n, vector<int>(n, 2));
        unordered_map<int, int>mp;
        int maxLength = 0;
        for(int i = 0; i < n; i++){
            mp[arr[i]] = i;
        }
        for(int j = 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                int target = arr[k] - arr[j];
                if(mp.count(target) && mp[target] < j){
                    int i = mp[target];
                    dp[j][k] = dp[i][j] + 1;
                }
                maxLength = max(maxLength, dp[j][k]);
            }
        }
        return maxLength >= 3 ? maxLength : 0;
    }
    int lenLongestFibSubseq(vector<int>& arr) {
        // return recursion(arr);
        // return memoization(arr);
        return tabulation(arr);
    }
};
// @lc code=end
