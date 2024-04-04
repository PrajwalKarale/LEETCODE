// T.c -> O(n)
// S.C -> O(n) because we are using two extra data strucure which are Bitset and vector

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
auto initialize = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

constexpr int MAX_NODES = 10000;

class Solution {
    bitset<MAX_NODES> visited;
public:
    bool dfs(unordered_map<int, vector<int>>& adjList, int node,int destination, vector<bool>&state) {
        if(visited[node]){
            return true;
        }
        // if the node is being already visited.
        if(state[node]){
            return false;
        }
        // What if the node is a leaf node but not the destination node at that time it should return false.
        if(adjList[node].size() == 0){
            return node == destination;
        }
        state[node] = true;
        for(auto &neigh: adjList[node]){
            if(!dfs(adjList, neigh, destination, state)){
                return false;
            }
        }
        //This we have to do while we backtrack
        state[node] = false;
        return visited[node] = true;
    }
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source,int destination) {
        unordered_map<int, vector<int>> adjList;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
        }
        vector<bool>state(n, false);
        return dfs(adjList, source, destination, state);
    }
};
