class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int patch = 0;
        long maxReachable = 0;
        int i = 0;
        while(maxReachable < n){
            if(i < nums.size() && nums[i] <= maxReachable + 1){
                // Include nums[i];
                maxReachable += nums[i];
                i++;
            }else{
                int patchNumber = maxReachable + 1;
                maxReachable += patchNumber;
                patch++;
            }
        }
        return patch;
    }
};
