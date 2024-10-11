/*
 * @lc app=leetcode id=962 lang=cpp
 *
 * [962] Maximum Width Ramp
 */

/*
    Time Complexity:
        1. We are traversing each and every element only once
        2. T.C -> O(n) where n are the number of elements in the array
    Space Complexity:
        1. We have created one vector to store the next greater element
        2. S.C -> O(n)
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
};
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int>maxElementToRight(n);
        maxElementToRight[n - 1] = nums[n - 1];

        for(int i = n - 2; i >= 0; i--){
            maxElementToRight[i] = max(maxElementToRight[i + 1], nums[i]);
        }

        int i = 0;
        int j = 0;
        int result = 0;
        while(j < n){
            while(nums[i] > maxElementToRight[j]){
                i++;
            }
            result = max(result, j - i);
            j++;
        }
        return result;
    }
};
