auto initialize = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>inDegree(numCourses, 0);
        unordered_map<int, vector<int>>adjList;
        // Firstly create Adjacency list
        for(vector<int>&edge: prerequisites){
            int a = edge[0];
            int b = edge[1];

            adjList[b].push_back(a);
            
            inDegree[a]++;
        }
        queue<int>q;
        int count = 0;
        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] == 0){
                count++;
                q.push(i);
            }
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int &v: adjList[u]){
                inDegree[v]--;
                if(inDegree[v] == 0){
                    count++;
                    q.push(v);
                }
            }
        }
        return numCourses == count;
    }
};
