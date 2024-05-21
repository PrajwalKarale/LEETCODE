// T.C -> O(n) since each element is visited just once in the input array
// S.C -> O(n) because we have used a vector<int>temp which can accomodate n elements.
auto speedUp = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

#pragma GCC optimize("Ofast")
#pragma GCC target("tune=native")
class Solution {
public:
    vector<vector<int>>result;
    void helper(vector<int>&nums,int index, vector<int>&temp){
        if(index >= nums.size()){
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        helper(nums,index + 1, temp);
        temp.pop_back();
        helper(nums,index + 1, temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        helper(nums, 0, temp);
        return result;
    }
};
