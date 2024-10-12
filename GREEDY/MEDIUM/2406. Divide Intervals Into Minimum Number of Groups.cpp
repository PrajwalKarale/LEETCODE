/*
    Time Complexity:
        1. Sorting takes O(n*log(n)) time and for loops takes O(n*log(n))
        2. T.C -> O(n * log(n))
    Space Conplexity:
        1. Since we have used a minHeap to store the end time of the interval
        2. S.C -> O(n)
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>>departureTime;
        for(int i = 0; i < n; i++){
            int arrival = intervals[i][0];
            int departure = intervals[i][1];
            if(!departureTime.empty() && arrival > departureTime.top()){   
                departureTime.pop();
            }
            departureTime.push(departure);
        }
        return departureTime.size();
    }
};
