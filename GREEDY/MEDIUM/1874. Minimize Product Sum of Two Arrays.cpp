/*
Time Complexity: O(n * log(n))
*/
class Solution {
public:
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n = nums1.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end(), greater<int>());
        int result = 0;
        for(int i = 0; i < n; i++){
            result = result + (nums1[i] * nums2[i]);
        }
        return result;
    }
};
