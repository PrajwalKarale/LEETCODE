/*
1. T.C -> Same as it is required for Djikstra Algorithm O(V.log(V) + E)
2. S.C -> O(E + V)
*/
class Solution {
    typedef pair<int, int> P;
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        // Initializing variables.
        priority_queue<P, vector<P>, greater<P>>pq;
        vector<int>result(n+1, INT_MAX);
        unordered_map<int, vector<P>>adjList;

        //Creating graph
        for(auto &time: times){
            int u = time[0];
            int v = time[1];
            int t = time[2];
            adjList[u].push_back({v,t});
        }

        result[k] = 0;
        pq.push({0, k});
        while(!pq.empty()){
            int node = pq.top().second;
            int t = pq.top().first;
            pq.pop();
            for(auto &neighbour: adjList[node]){
                int v = neighbour.first;
                int time = neighbour.second;
                if(t + time < result[v]){
                    result[v] = t + time;
                    pq.push({t + time, v});
                }
            }
        }

        int ans = INT_MIN;
        for(int i = 1; i <= n; i++){
            ans = max(ans, result[i]);
        }
        return ans == INT_MAX ? -1: ans;
    }
};
