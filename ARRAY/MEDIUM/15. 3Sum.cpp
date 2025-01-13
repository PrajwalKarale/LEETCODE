auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    void twoSum(vector<int>&nums, int n1, int target, int i, int j, vector<vector<int>>&result){
        while(i < j){
            if(nums[i] + nums[j] > target){
                j--;
            }else if(nums[i] + nums[j] < target){
                i++;
            }else{
                while(i < j && nums[i] == nums[i+1]){
                    i++;
                }
                while(i < j && nums[j] == nums[j - 1]){
                    j--;
                }
                result.push_back({-target, nums[i], nums[j]});
                i++;
                j--;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n < 3){
            return {};
        }
        sort(nums.begin(), nums.end());
        vector<vector<int>>result;
        for(int i = 0; i < n-2; i++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            int n1 = nums[i];
            int target = -1 * n1;
            twoSum(nums, n1, target, i + 1, n - 1, result);
        }
        return result;
    }
};
