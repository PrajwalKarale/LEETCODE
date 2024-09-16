#pragma GCC optimize("Ofast", "inline", "fast-math", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")

static bool _ = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return false;
}();
/*
    Time Complexity:
        1. For creating adjList the time needed is O(V + E)
        2. T.C -> O(N)
    Space Complexity:
        1. unordered_map takes O(V + E)
*/
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1){
            return {0};
        }
        vector<int>inDegree(n);
        // Creating adjancency list
        unordered_map<int,vector<int>>adjList;
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];
            //Since it is an undirected graph
            inDegree[u]++;
            inDegree[v]++;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        queue<int>q;
        vector<int> result;
        for(int i = 0; i < n; i++){
            if(inDegree[i] == 1){
                q.push(i);
            }
        }
        // Since we know that any graph with given nodes we can at most one or two mht
        while(n > 2){
            int size = q.size();
            n = n - size;
            while(size--){
                int u = q.front();
                q.pop();
                for(int &v: adjList[u]){
                    inDegree[v]--;
                    if(inDegree[v] == 1){
                        q.push(v);
                    }
                }
            }
        }
        while(!q.empty()){
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
};
