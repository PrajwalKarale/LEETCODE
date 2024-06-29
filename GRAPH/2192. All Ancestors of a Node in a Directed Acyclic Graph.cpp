auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    void bfs(int node, unordered_map<int, vector<int>> &adjList, vector<vector<int>>&result){
        unordered_set<int>visited;
        queue<int>q;
        q.push(node);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto &neighbour: adjList[u]){
                if(visited.find(neighbour) == visited.end()){
                    q.push(neighbour);
                    visited.insert(neighbour);
                }
            }
        }
        vector<int>ancestors(visited.begin(), visited.end());
        sort(ancestors.begin(), ancestors.end());
        result[node] = ancestors;
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>>adjList;
        vector<vector<int>>result(n);

        for(int i = 0; i < n; i++){
            adjList[i] = {};
        }

        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];
            adjList[v].push_back(u);
        }
        for(int i = 0; i < n; i++){
            bfs(i, adjList, result);
        }
        return result;
    }
};
