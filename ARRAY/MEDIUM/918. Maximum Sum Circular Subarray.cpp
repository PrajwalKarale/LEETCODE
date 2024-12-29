/*
    Logic:
        1. BruteForce:
            a. We know that if n is the length of the array and we rotate the array n times we get the same array. So everytime we rotate the array and     find maximum sum subarray using Kadanes Algorithm we will get the maximum sum in the circular subarray.
        2. Optimised Approach
            a. Consider s to be the sum of the array and s_max to be the sum of maximum sum of a circular subarray
            so s_min = s - s_max
            b. By contradiction we will prove that s_max = s - s_min
            c. Our Algorithm will be as follows:
                1. Finding Sum of the whole array
                2. Maximum sum of the subarray
                3. Minimum sum of the subarray
                4. s_min = s - s_max(maximum sum of circular subarray)

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
    int kadanesMax(vector<int>&nums){
        int sum = nums[0];
        int maxSum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            sum = max(sum + nums[i], nums[i]);
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
    int kadaneMin(vector<int>&nums){
        int sum = nums[0];
        int minSum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            sum = min(sum + nums[i], nums[i]);
            minSum = min(minSum, sum);
        }
        return minSum;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int circularSum = 0;
        int maximumSubarraySum = 0;
        int minimumSubarraySum = 0;

        int arraySum = accumulate(nums.begin(), nums.end(), 0);
        maximumSubarraySum = kadanesMax(nums);
        minimumSubarraySum = kadaneMin(nums);
        circularSum = arraySum - minimumSubarraySum;

        if(maximumSubarraySum > 0){
            return max(maximumSubarraySum, circularSum);
        }
        return maximumSubarraySum;
    }
};
