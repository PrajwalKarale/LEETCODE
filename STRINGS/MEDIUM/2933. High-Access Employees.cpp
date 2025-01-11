/*
 * @lc app=leetcode id=2933 lang=cpp
 *
 * [2933] High-Access Employees
 */
/*
    Logic:
    Time Complexity:
        1. The main time complexity is taken by sorting the vector
        2. T.C -> O(n * log(n))
    Space Complexity:
        1. We are using unordered_map as an auxiliary space
        2. S.C -> O(n)
*/
// @lc code=start
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string,vector<int>>mp;
        vector<string>result;
        for(int i = 0; i < access_times.size(); i++){
            string employee = access_times[i][0];
            int time = stoi(access_times[i][1]);
            mp[employee].push_back(time);
        }
        for(auto &it: mp){
            sort(it.second.begin(), it.second.end());
        }
        for(auto &it:mp){
            vector<int> &employeeTime = it.second;
            for(int i = 2; i < employeeTime.size(); i++){
                if(employeeTime[i] - employeeTime[i-2] < 100){
                    result.push_back(it.first);
                    break;
                }
            }
        }
        return result;
    }
};
// @lc code=end

