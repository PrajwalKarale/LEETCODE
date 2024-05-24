// T.C: Since at every function call we have two choices whether to include in subset or not include in subset. So overall complexity is: O(2^n)
// S.C: We have used Map as an auxiliary space so O(n)

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
    int count;
    void solve(vector<int>&nums, unordered_map<int,int>&mp, int k, int index){
        // Base Case
        if(index >= nums.size()){
            count++;
            return;
        }
        if(!mp[nums[index] - k] && !mp[nums[index] + k]){
            mp[nums[index]]++;
            // Take nums[i]
            solve(nums, mp, k, index + 1);
            mp[nums[index]]--;
        }
        //Skip nums[i]
        solve(nums, mp, k, index + 1);
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        count = 0;
        unordered_map<int,int> mp;
        solve(nums, mp, k, 0);

        return count - 1;
    }
};
