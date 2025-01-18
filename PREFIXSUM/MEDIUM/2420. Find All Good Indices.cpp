/*
    Logic:
        1. We will use the Prefix array logic in this case which is we will find the length of the increasing or decreasing sequence at every index.
    Time Complexity:
        1. We are traversing the `nums` array twice
        2. T.C -> O(2*n)
    Space Complexity:
        1. We are using two vectors as an auxiliary space.
        2. S.C -> O(2*n)
*/
// @lc code=start
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        vector<int>result;
        int n = nums.size();
        vector<int>nonIncreasing(n, 1);
        vector<int>nonDecreasing(n, 1);
        for(int i = 1; i < n; i++){
            if(nums[i] <= nums[i - 1]){
                nonIncreasing[i] = 1 + nonIncreasing[i - 1];
            }
        }
        for(int i = n - 2; i >= 0; i--){
            if(nums[i] <= nums[i + 1]){
                nonDecreasing[i] = 1 + nonDecreasing[i + 1];
            }
        }
        for(int i = k; i < n - k; i++){
            if(nonIncreasing[i - 1] >= k && nonDecreasing[i + 1] >= k){
                result.push_back(i);
            }
        }
        return result;
    }
};
