/*
 * @lc app=leetcode id=802 lang=cpp
 *
 * [802] Find Eventual Safe States
 */
/*
    Logic:
        1. Main logic is that whenever we detect a cycle that node will not lead to Safe Node because
        we need each and every path from the safe node to go to the terminal node.
        2. Here we can do two approaches finding cycle by DFS and BFS. I am preferring BFS for which we will be using Topological Sorting
    Time Complexity:
        1. We are creating a adjList and doing Topological Sortinh
        1. T.C -> TC1 + TC2 -> O(v^2) + O(v + e)
    Space Complexity:
        1. We are using auxiliary space like adjList, inDegree, q, isSafe
        2. S.C -> SC1 + SC2 + SC3 + SC4 -> O(v^2)
*/
// @lc code=start
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // Total number of nodes
        int v = graph.size();
        vector<int>result;
        //SC1 -> O(v*v)
        vector<vector<int>>adjList(v);
        //SC2 -> O(v)
        vector<int>inDegree(v, 0);
        // TC1 -> O(v*v)
        for(int u = 0; u < v; u++){
            for(auto &neighbour: graph[u]){
                adjList[neighbour].push_back(u);
                inDegree[u]++;
            }
        }
        // Basis of Topological Sort
        //SC3 -> O(v)
        queue<int>q;
        //TC2 -> O(V + E)
        for(int i = 0; i < v; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        // Every terminal node is a safe node
        //SC4 -> O(v)
        vector<bool>isSafe(v, false);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            isSafe[node] = true;
            for(auto &neighbour: adjList[node]){
                inDegree[neighbour]--;
                if(inDegree[neighbour] == 0){
                    q.push(neighbour);
                }
            }
        }
        for(int i = 0; i < v; i++){
            if(isSafe[i] == true){
                result.push_back(i);
            }
        }
    return result;
    }
};
// @lc code=end

