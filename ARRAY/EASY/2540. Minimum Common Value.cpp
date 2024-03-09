class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        set<int> s;
        for(int &num: nums2){
            s.insert(num);
        }
        int minValue = INT_MAX;
        for(int i = 0; i < nums1.size(); i++){
            if(s.find(nums1[i]) != s.end()){
                minValue = min(minValue, nums1[i]);
            }
        }
        return minValue == INT_MAX ? -1 : minValue;
    }
};
