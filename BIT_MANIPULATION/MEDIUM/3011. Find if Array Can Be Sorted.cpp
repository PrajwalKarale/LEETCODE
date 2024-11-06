/*
    Time Complexity:
        1. T.C -> O(n^2)
    Space Complexity:
        1. S.C -> O(1)
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n - i - 1; j++){
                if(nums[j] <= nums[j + 1]){
                    continue;
                }else{
                    if(__builtin_popcount(nums[j]) == __builtin_popcount(nums[j + 1])){
                        swap(nums[j], nums[j + 1]);
                    }else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
