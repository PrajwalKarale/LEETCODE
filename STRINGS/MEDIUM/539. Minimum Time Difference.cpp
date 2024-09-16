/*
 * @lc app=leetcode id=539 lang=cpp
 *
 * [539] Minimum Time Difference
 */

// @lc code=start
/*
  Time Complexity: O(n * log(n))
  Space Complexity: O(n) since we created mintesConverted array.
*/
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n = timePoints.size();
        vector<int>minutesConverted;
        for(int i = 0; i < n; i++){
            string hours = timePoints[i].substr(0, 2);
            string minutes = timePoints[i].substr(3);
            int hoursPassed = stoi(hours);
            int minutesPassed = stoi(minutes);
            minutesConverted.push_back(60*hoursPassed + minutesPassed);
        }
        sort(minutesConverted.begin(), minutesConverted.end());
        int result = INT_MAX;
        for(int i = 1; i < n; i++){
            result = min(result, minutesConverted[i] - minutesConverted[i - 1]);
        }
        return min(result, (24*60 - minutesConverted[n-1]) + minutesConverted[0]);
    }
};
// @lc code=end
