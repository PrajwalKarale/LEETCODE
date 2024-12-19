/*
    Logic:
        1. One approach I can think is merge both the arrays and then sort it and then find the median. But it will take n*log(n) time since we do sorting.
        2. Optimised Approach is using Binary Search and finding the optimised partition.
    Time Complexity:
        1. T.C -> O(log(min(nums1.size(), nums2.size())))
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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()){
            return findMedianSortedArrays(nums2, nums1);
        }
        int m = nums1.size();
        int n = nums2.size();
        int left = 0;
        int right = m;
        while(left <= right){
            int px = left + (right - left)/2;
            int py = ((m + n + 1) / 2) - px;
            int x1,x2,x3,x4;
            if(px == 0){
                x1 = INT_MIN;
            }else{
                x1 = nums1[px - 1];
            }
            if(py == 0){
                x2 = INT_MIN;
            }else{
                x2 = nums2[py - 1];
            }
            if(px == m){
                x3 = INT_MAX;
            }else{
                x3 = nums1[px];
            }
            if(py == n){
                x4 = INT_MAX;
            }else{
                x4 = nums2[py];
            }
            // Perfect partitioning condition
            if((x1 <= x4) && (x2 <= x3)){
                if((m + n) % 2 == 1){
                    return max(x1,x2);
                }
                return (max(x1,x2) + min(x3,x4)) / 2.0;
            }
            // Non perfect partitioning condition
            if(x1 > x4){
                right = px - 1;
            }else{
                left = px + 1;
            }
        }
        return -1.0;
    }
};
