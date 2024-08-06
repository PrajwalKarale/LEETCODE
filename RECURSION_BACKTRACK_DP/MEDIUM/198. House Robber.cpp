class Solution {
public:
    int n;
    int memo[1001];
    int solveByDP(vector<int>&nums){
        vector<int>t(n + 1);
        t[0] = 0;
        t[1] = nums[0];
        for(int i = 2; i <= n; i++){
            int steal = nums[i - 1] + t[i - 2];
            int skip = t[i - 1];
            t[i] = max(steal, skip);
        }
        return t[n];
    }
    int solveByMemoization(vector<int>&nums, int i){
        if(memo[i] != -1){
            return memo[i];
        }
        if(i >= n){
            return 0;
        }
        int take = nums[i] + solveByMemoization(nums, i + 2);
        int skip = solveByMemoization(nums, i + 1);
        return memo[i] = max(take, skip);
    }
    int rob(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        n = nums.size();
        // return solveByRecursion(nums, 0);
        memset(memo, -1, sizeof(memo));
        // return solveByMemoization(nums, 0);
        return solveByDP(nums);
    }
};
