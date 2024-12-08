/*
    Logic:
        1. Since they have mentioned that "You may assume that both players are playing optimally." we can get that its a question of optimal game strategy
        2. In optimal Game Strategy 
            "When its your chance -> Do your best(max)"
            "When is your opponent turn -> Opponent will select what is best for him so after your opponents turn you will get the wors which is min"
            This is called max-min Game Strategy
    Time Complexity:
        1. During Recursion since each step has 2 outcomes so T.C -> O(2^n)
        2. Memoization brings down the T.C -> (n^2)
    Space Complexity:
        1. For recursion its the height of the recursive tree which is formed
        2. S.C -> O(n^2)
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    // int helper(int i, int j, vector<int>&nums){
    //     if(i > j){
    //         return 0;
    //     }
    //     int takeI = nums[i] + min(
    //         helper(i + 2, j, nums), 
    //         helper(i + 1, j - 1, nums)
    //     );
    //     int takeJ = nums[j] + min(
    //         helper(i + 1, j - 1, nums),
    //         helper(i, j - 2, nums)
    //     );
    //     return max(takeI, takeJ);
    // }
    // bool recursiveApproach(vector<int>&nums){
    //     int n = nums.size();
    //     int totalScore = 0;
    //     for(int &num: nums){
    //         totalScore += num;
    //     }
    //     int player1 = helper(0, n - 1, nums);
    //     int player2 = totalScore - player1;
    //     return player1 >= player2;
    // }
    int memoHelper(int i, int j, vector<int>&nums, vector<vector<int>>&dp){
        if(i > j){
            return      0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int takeI = nums[i] + min(
            memoHelper(i + 2, j, nums, dp), 
            memoHelper(i + 1, j - 1, nums, dp)
        );
        int takeJ = nums[j] + min(
            memoHelper(i + 1, j - 1, nums, dp),
            memoHelper(i, j - 2, nums, dp)
        );
        return dp[i][j] = max(takeI, takeJ);
    }
    bool memoization(vector<int>&nums){
        vector<vector<int>>dp(23, vector<int>(23,-1));
        int n = nums.size();
        int totalScore = 0;
        for(int &num: nums){
            totalScore += num;
        }
        int player1 = memoHelper(0, n - 1, nums, dp);
        int player2 = totalScore - player1;
        return player1 >= player2;
    }
    bool predictTheWinner(vector<int>& nums) {
        // return recursiveApproach(nums);
        return memoization(nums);
    }
};
