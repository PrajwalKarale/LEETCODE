/*
Trick for any problem for solving circular subarray
1. T.C
    a. For loop for finding 'totalNumberOfOnes' is O(n);
    b. while loop also takes O(n)
    c. Total T.C is O(2*n)
2. S.C
    b. Since no extra space is taken we have S.C -> O(1)
*/
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        int totalNumberOfOnes = 0;
        for(int &num: nums){
            if(num == 1){
                totalNumberOfOnes += 1;
            }
        }
        // nums.insert(nums.end(), nums.begin(), nums.end());
        int currentOnes = 0;
        for(int i = 0; i < totalNumberOfOnes; i++){
            if(nums[i] == 1){
                currentOnes+= 1;
            }
        }
        int minSwaps = totalNumberOfOnes - currentOnes;
        int left = 0;
        int right = totalNumberOfOnes;
        while(right < 2*nums.size()){
            if(nums[left % nums.size()] == 1){
                currentOnes--;
            }
            left++;
            if(nums[right % nums.size()] == 1){
                currentOnes++;
            }
            right++;
            minSwaps = min(minSwaps, totalNumberOfOnes - currentOnes);
        }
        return minSwaps;
    }
};
