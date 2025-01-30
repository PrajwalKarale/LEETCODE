// @lc code=start
/*
    Logic:
        1. We have to find that extra edge that is causing cyclic nature in the graph.
        2. We will travel through the edges and check whether each node is present in the graph or not.
        3. If both the nodes are present we will check whether they were already connected. Another Approach is DSU but we will see it next time
    Time Complexity:
        1. TC1 -> O(edges.length())*O(BFS)
               -> O(n * O(V + E)) where V represents the number of nodes and E represents the number of Edges in the graph
               -> O(n^2) for worst case.
    Space Complexity:
        1. We are using auxiliary space which is adjList, queue, visited
        2. SC -> SC1 + SC2 + SC3
              -> O(n) + O(n) + O(n) where n is the number of nodes
           SC -> O(n)
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    bool bfs(unordered_map<int,vector<int>>&adjList, vector<bool>&visited, int u, int v){
        visited[u] = true;
        //SC2 -> O(n)
        queue<int>q;
        q.push(u);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto neighbour: adjList[node]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
        return visited[v];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        // SC1 -> O(n)
        unordered_map<int, vector<int>>adjList;
        // TC1 -> O(edges.length()) + O(BFS)
        for(vector<int>&edge: edges){
            int u = edge[0];
            int v = edge[1];
            // SC3 -> O(n)
            vector<bool>visited(n, false);
            if((adjList.find(u) != adjList.end()) && (adjList.find(v) != adjList.end()) && bfs(adjList, visited, u, v)){
                return edge;
            }
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        return {};
    }
};
// @lc code=end

