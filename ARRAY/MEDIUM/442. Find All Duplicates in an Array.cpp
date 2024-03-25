class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<int>dup;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int indexOfnum = abs(nums[i]) - 1;
            nums[indexOfnum] = -1 * nums[indexOfnum];
            if(nums[indexOfnum] > 0){
                dup.push_back(indexOfnum + 1);
            }
        }
        return dup;
    }
};
