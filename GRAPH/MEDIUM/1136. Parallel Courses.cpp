class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        unordered_map<int, vector<int>>adjList;
        vector<int>inDegree(n+1, 0);
        for(auto& relation: relations){
            adjList[relation[0]].push_back(relation[1]);
            inDegree[relation[1]]++;
        }
        queue<int>q;
        for(int i = 1; i <= n; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        //q -> 1,2
        int semesters = 0;
        int coursesStudied = 0;
        while(!q.empty()){
            semesters++;
            int qSize = q.size();
            for(int i = 0; i < qSize; i++){
                int curr = q.front();
                q.pop();
                coursesStudied += 1;
                for(auto &neighbour: adjList[curr]){
                    inDegree[neighbour] -= 1;
                    if(inDegree[neighbour] == 0){
                        q.push(neighbour);
                    }
                }
            }
        }
        return coursesStudied == n ? semesters : -1;
    }
};
