/*
 * @lc app=leetcode id=1331 lang=cpp
 *
 * [1331] Rank Transform of an Array
 */

// @lc code=start
const int fastIO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>arr1 = arr;
        sort(arr1.begin(), arr1.end());
        unordered_map<int,int>indices;
        int index = 1;
        for(int &num: arr1){
            if(indices.find(num) == indices.end()){
                indices[num] = index;
                index += 1;
            }

        }
        vector<int>result;
        for(int &num: arr){
            result.push_back(indices[num]);
        }
        return result;
    }
};
// @lc code=end
