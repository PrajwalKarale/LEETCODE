#pragma GCC optimize("03")
static int __star = []{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL),cout.tie(NULL);
    return 0;
}();
using ll = long long;
class Solution {
public:
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        ll result = 0;
        int n = nums1.size();
        vector<int>diff(n, 0);

        for(int i = 0; i < n; i++){
            diff[i] = nums1[i] - nums2[i];
        }
        sort(diff.begin(), diff.end());
        int left = 0;
        int right = n - 1;
        while(left < right){
            if(diff[left] + diff[right] > 0){
                result += (right - left);
                right--;
            }else{
                left++;
            }
        }
        return result;
    }
};
