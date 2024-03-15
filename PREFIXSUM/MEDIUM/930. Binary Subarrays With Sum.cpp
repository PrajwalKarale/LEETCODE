class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // We are going through prefix sum and hashmap.
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n = nums.size();
        unordered_map<int,int>sum;
        
        //Since our initial prefix Sum is zero
        sum[0] = 1;
        int currentSum = 0;
        int result = 0;
        for(int &num: nums){
            currentSum += num;
            int requiredSum = currentSum - goal;
            if(sum.find(requiredSum) != sum.end()){
                result += sum[requiredSum];
            }
            sum[currentSum]++;
        }
        return result;
    }
};
