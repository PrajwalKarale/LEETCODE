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
    vector<vector<int>>result;
    void solve(vector<int>&nums, vector<int>&temp, int i){
        if(i >= nums.size()){
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(nums, temp, i+1);
        temp.pop_back();
        while(i + 1 < nums.size() && nums[i] == nums[i+1]){
            i++;
        }
        solve(nums,temp, i + 1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        solve(nums, temp, 0);
        return result;
    }
};
