/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */

// @lc code=start
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        auto comparator = [](int &a, int &b){
            string s1 = to_string(a);
            string s2 = to_string(b);
            if(s1 + s2 > s2 + s1){
                return true;
            }
            return false;
        };
        sort(nums.begin(), nums.end(), comparator);
        if(nums[0] == 0){
            return "0";
        }
        string result = "";
        for(int &num: nums){
            string stringNum = to_string(num);
            result = result + stringNum;
        }
        return result;
    }
};
// @lc code=end

