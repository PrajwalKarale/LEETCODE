/*
    Here the sorting requires O(nlogn) time
    Consider d as the number of digits in x
    The convert function takes O(d) time
    nums.length() = n. So therefore for every number in nums we call convert function
    T.C -> O(n)
*/
class Solution {
public:
    int convert(int x, vector<int>&mapping){
        if(x == 0){
            return mapping[0];
        }
        int z = 0;
        for(int power = 1; x > 0; power = power * 10){
            int r = x % 10;
            int q = x / 10;
            z = z + mapping[r]*power;
            x = q;
        }
        return z;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<pair<int,int>>mapNum;
        for(int i = 0; i < nums.size(); i++){
            int x = nums[i];
            int mappedNumber = convert(x, mapping);
            mapNum.push_back({mappedNumber, i});
        }
        sort(mapNum.begin(), mapNum.end());
        vector<int>ans(nums.size());
        for(int i = 0; i < nums.size(); i++){
            ans[i] = nums[mapNum[i].second];
        }
        return ans;
    }
};
