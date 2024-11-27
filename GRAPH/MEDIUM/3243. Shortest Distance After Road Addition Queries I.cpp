/*
    Time Complexity:
        1. We are running BFS for the number of times of queries
        2. T.C -> O(Q * (V + E)) where Q are the total number of queries and V are the total number of nodes and E are the total number of edges present in the graph
    Space Complexity:
        1. We are using queue as an extra space and also visited array.
        2. S.C -> O(n)
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    int bfs(unordered_map<int, vector<int>>&adjList, int n){
        queue<int>q;
        vector<bool>visited(n, false);
        q.push(0);
        visited[0] = true;
        int level = 0;
        while(!q.empty()){
            int qSize = q.size();
            while(qSize--){
                int node = q.front();
                q.pop();
                if(node == n - 1){
                    return level;
                }
                for(int &neighbour: adjList[node])
                if(visited[neighbour] == false){
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
            level++;
        }
        return -1;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int>result;
        unordered_map<int,vector<int>>adjList;
        for(int i = 0; i < n - 1; i++){
            adjList[i].push_back(i+1);
        }
        for(vector<int>&query: queries){
            int u = query[0];
            int v = query[1];
            adjList[u].push_back(v);
            int d = bfs(adjList,n);
            result.push_back(d);
        }
        return result;
    }
};
