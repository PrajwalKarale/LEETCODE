#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

auto initialize = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1){
            return n;
        }
        int result = 1;
        int i = 1;
        int increasingSubarray = 1;
        int decreasingSubarray = 1;
        while(i < n){
            // if increasing sequence is detected
            if(nums[i] > nums[i - 1]){
                increasingSubarray++;
                decreasingSubarray = 1;
            }else if(nums[i] < nums[i - 1]){// if decreasing sequence is detected
                decreasingSubarray++;
                increasingSubarray = 1;
            }else{
                increasingSubarray = 1;
                decreasingSubarray = 1;
            }
            result = max(result, max(increasingSubarray, decreasingSubarray));
            i++;
        }
        return result;
    }
};
