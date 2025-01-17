/*
    Logic:
        1. Fleet is only possible when a car catches up with another car.  If car F is forward car B then if time needed for B to reach target is less than time needed
        for F to reach target then car F and car B will form a fleet.
    Time Complexity:
        1. Sorting takes O(n*log(n))
        2. For loop takes O(n)
        3. T.C -> O(n*log(n)) + O(n)
    Space Complexity:
        1. Since we have used stack as an ausiliary space
        2. S.C -> O(n)
*/
// @lc code=start
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int result;
        vector<pair<int, double>>ps;
        int pSize = position.size();
        int sSize = speed.size();
        for(int i = 0; i < pSize; i++){
            int posI = position[i];
            int speedI = speed[i];
            double timeToReach = (double)(target - posI) / speedI;
            ps.push_back({posI, timeToReach});
        }
        sort(ps.begin(), ps.end(), [](auto& a, auto& b) {
            return a.first > b.first;
        });
        stack<double>s;
        for (int i = 0; i < ps.size(); i++) {
            double time = ps[i].second;
            if (s.empty() || time > s.top()) {
                s.push(time); // New fleet starts
            }
        }
        result = s.size();
        return result;
    }
};
