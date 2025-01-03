/*
    Logic: Prefix Sum
    Time Complexity:
        1. T.C -> O(n)
    Space Complexity:
        1. S.C -> O(2*n) since two vectors have been used
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        vector<long>sumOfFirst(n, 0);
        vector<long>sumOfLast(n, 0);
        sumOfFirst[0] = nums[0];
        sumOfLast[n-1] = nums[n - 1];
        for(int i = 1; i < n; i++){
            sumOfFirst[i] = sumOfFirst[i - 1] + nums[i];
        }
        for (int i = n - 2; i >= 0; i--) {
            sumOfLast[i] = sumOfLast[i + 1] + nums[i];
        }
        for(int i = 0; i < n-1; i++){
            if(sumOfFirst[i] >= sumOfLast[i + 1]){
                result++;
            }
        }
        return result;
    }
};
