/*
    Logic:
        1. Prefix Sum
    Time Complexity:
        1. T.C -> O(n)
    Space Complexity:
        1. S.C -> O(n)
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix(n, 0);
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i - 1] + nums[i];
        }
        int minPrefix = *min_element(prefix.begin(), prefix.end());
        if(minPrefix >= 1){
            return 1;
        }
        return 1 - minPrefix;
    }
};
