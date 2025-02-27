/*
    Logic:
        1. Whenever maximum sum subarray is asked in the question always remember Kadanes algorithm.
        2. Since they have mentioned absolute value that means we have to consider negative numbers too. 
           So there can be a possibility that the sum of negative numbers would be greater than the sum of positive number.
    Time Complexity:
        1. T.C -> O(n)
    Space Complexity:
        1. S.C -> O(1)
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int maxSubArraySum = nums[0];
        int currSubArraySum = nums[0];
        for(int i = 1; i < n; i++){
            currSubArraySum = max(nums[i], currSubArraySum + nums[i]);
            maxSubArraySum = max(maxSubArraySum, currSubArraySum);
        }
        int minSubArraySum = nums[0];
        currSubArraySum = nums[0];
        for(int i = 1; i < n; i++){
            currSubArraySum = min(nums[i], currSubArraySum + nums[i]);
            minSubArraySum = min(minSubArraySum, currSubArraySum);
        }
        maxSubArraySum = abs(maxSubArraySum);
        minSubArraySum = abs(minSubArraySum);
        return max(maxSubArraySum, minSubArraySum);
    }
};
