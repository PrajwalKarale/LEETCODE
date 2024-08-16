/*
Time Complexity
    1. O(n) where n = arrays.size()
*/
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int minimum1 = arrays[0][0];
        int maximum1 = arrays[0].back();
        int distance = INT_MIN;
        int m = arrays.size();
        for(int i = 1; i < m; i++){
            distance = max(distance, abs(arrays[i].back() - minimum1));
            distance = max(distance, abs(arrays[i][0] - maximum1));
            
            minimum1 = min(minimum1, arrays[i][0]);
            maximum1 = max(maximum1, arrays[i].back());
        }
        return distance;
    }
};
