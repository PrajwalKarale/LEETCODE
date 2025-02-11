/*
 * @lc app=leetcode id=410 lang=cpp
 *
 * [410] Split Array Largest Sum
 */
/*
    Logic:
        1. a = 7,2,5,10,8  k = 2 that means two partitions are allowed. The possible partitions are as follows
            [7],[2,5,10,8]     maxSum -> 25
            [7,2], [5,10,8]    maxSum -> 23
            [7,2,5], [10,8]     maxSum -> 18
            [7,2,5,10], [8]    maxSum -> 24
            Out of the maxSum we have to find min(maxSum) which is 18 
        2. So we can think in the following way that we have the maxSum and we have to check that whether with the given maxSum the array can be split into k parts or not.
        3. It seems familiar to Binary Search on answers. So we will proceed with that. When we do a dry run at that time we can see that we have to return `low`
    Time Complexity:
        1. For finding `high` variable we are taking O(n) time.
        2. Then we are applying binary search so while applying binary search we are calling function `partitionSplit` which takes O(n) time so the overall time complexity will be O(n*log(n))
        3. T.C -> O(n) + O(n *log(n))
    Space Complexity:
        1. We havent used any auxiliary space so our S.C -> O(1)
*/
// @lc code=start
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    int partitionSplit(vector<int>&nums, int n, int mid){
        // Intial partition should be 1
        int partitions = 1;
        int partitionSum = 0;
        for(int i = 0; i < n; i++){
            if(partitionSum + nums[i] <= mid){
                partitionSum += nums[i];
            }else{
                partitions++;
                partitionSum = nums[i];
            }
        }
        return partitions;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while(low <= high){
            int mid = (low + high) / 2;
            int numberOfPartition = partitionSplit(nums, n, mid);
            if(numberOfPartition > k){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return low;   
    }
};
