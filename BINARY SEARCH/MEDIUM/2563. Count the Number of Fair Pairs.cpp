/*
    Time Complexity: 
        1. T.C -> O(n * log(n)) since we are performing sorting on the list
    Space Complexity:
        1. S.C -> O(1) since no extra space is used
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        long long result = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int index = lower_bound(begin(nums) + i + 1, end(nums), lower - nums[i]) - begin(nums);
            int x = index - i - 1;
            index = upper_bound(begin(nums) + i + 1, end(nums), upper - nums[i]) - begin(nums);
            int y = index - i - 1;
            result += (y - x);
        }
        return result; 
    }
};
