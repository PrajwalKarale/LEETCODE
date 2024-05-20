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
    vector<int> result;
    void help(vector<int>&nums, int index, int xorSubSet){
        if(index == nums.size()){
            result.push_back(xorSubSet);
            return;
        }
        help(nums, index + 1, xorSubSet ^ nums[index]);
        help(nums, index + 1, xorSubSet);
    }
    int subsetXORSum(vector<int>& nums) {
        help(nums, 0, 0);
        return accumulate(result.begin(), result.end(), 0);
    }
};
