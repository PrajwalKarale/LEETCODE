/*
    Logic:
    Time Complexity:
        1. From TC1 and TC2 we can conclude that T.C -> O(n)
    Space Complexity:
        1. From SC1 and SC2 we can conculde that S.C -> O(n)
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
// @lc code=start
class Solution {
public:
    // int bruteForce(vector<int>& nums, int k){
    //     int result = 0;
    //     int n = nums.size();
    //     for(int i = 0; i < n; i++){
    //         int sum = 0;
    //         for(int j = i; j < n; j++){
    //             sum = accumulate(nums.begin() + i, nums.begin() + j + 1, 0);
    //         }
    //         if(sum == k){
    //             result += 1;
    //         }
    //     }
    //     return result;
    // }
    int optimised(vector<int>&nums, int k){
        int n = nums.size();
        // SC1 -> O(n)
        vector<int>prefixSum(n, 0);
        // SC2 -> O(n)
        unordered_map<int,int>mp;
        int result = 0;
        prefixSum[0] = nums[0];
        // TC1 -> O (n)
        for(int i = 1; i < n; i++){
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }
        // TC2 -> O(n)
        for(int j = 0; j < n; j++){
            if(prefixSum[j] == k){
                result += 1;
            }
            int val = prefixSum[j] - k;
            if(mp.find(val) != mp.end()){
                result = result + mp[val];
            }
            if(mp.find(prefixSum[j]) == mp.end()){
                mp[prefixSum[j]] = 0;
            }
            mp[prefixSum[j]]++;
        }
        return result;
    }
    int subarraySum(vector<int>& nums, int k) {
        // return bruteForce(nums, k);
        return optimised(nums, k);
    }
};
// @lc code=end

