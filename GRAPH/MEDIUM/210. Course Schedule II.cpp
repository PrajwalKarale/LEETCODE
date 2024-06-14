class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<int>result;
        vector<int>inDegree(numCourses, 0);
        // Creating adjacency list of the graph
        unordered_map<int, vector<int>>adjList;
        for(vector<int>&edge: prerequisites){
            int a = edge[0];
            int b = edge[1];
            adjList[b].push_back(a);
            inDegree[a]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            result.push_back(u);
            for(auto &v: adjList[u]){
                inDegree[v]--;
                if(inDegree[v] == 0){
                    q.push(v);
                }
            }
        }
        if(result.size() == numCourses){
            return result;
        }
        return {};
    }
};
