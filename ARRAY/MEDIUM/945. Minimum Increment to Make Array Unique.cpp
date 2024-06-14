class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        sort(nums.begin(), nums.end());
        int moves = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] <= nums[i - 1]){
                int increamentRequired = nums[i - 1] - nums[i] + 1;        
                nums[i] += increamentRequired;
                moves += increamentRequired;
            }
        }
        cout << moves << endl;
        return moves;
    }
};
