/*
Time Complexity: O(E log(N)) where N is the number of nodes and E is number of edges
Space Complexity: O(N + E)
*/
static const int _ = []{cin.tie(0);ios::sync_with_stdio(0);return 0;}();
class Solution {
public:
    typedef pair<double,int> p;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int, vector<p>>adjList;
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            adjList[u].push_back({prob, v});
            adjList[v].push_back({prob, u});
        }
        vector<double>result(n, 0);
        result[start_node] = 1;
        priority_queue<p>pq;
        pq.push({1.0, start_node});
        while(!pq.empty()){
            int node = pq.top().second;
            double probability = pq.top().first;
            pq.pop();
            for(auto &neigh: adjList[node]){
                int adjNode = neigh.second;
                double adjNodeProb = neigh.first;
                if(result[adjNode] < probability * adjNodeProb){
                    result[adjNode] = probability * adjNodeProb;
                    pq.push({result[adjNode], adjNode});
                }
            }
        }
        return result[end_node];
    }
};
