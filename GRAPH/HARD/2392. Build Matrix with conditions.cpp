class Solution {
public:
    vector<int> topologicalSort(unordered_map<int, vector<int>>&graph, queue<int>&q, vector<int>&inDegree){
        vector<int>result;
        while(!q.empty()){
            int curr = q.front();
            result.push_back(curr);
            q.pop();
            for(auto &v: graph[curr]){
                inDegree[v]--;
                if(inDegree[v] == 0){
                    q.push(v);
                }
            }
        }
        return result;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        unordered_map<int, vector<int>>graphRow;
        unordered_map<int, vector<int>>graphCol;
        vector<int>inDegreeRow(k+1, 0);
        vector<int>inDegreeCol(k+1, 0);
        for(auto &row: rowConditions){
            graphRow[row[0]].push_back(row[1]);
            inDegreeRow[row[1]]++;
        }
        for(auto &column: colConditions){
            graphCol[column[0]].push_back(column[1]);
            inDegreeCol[column[1]]++;
        }
        vector<int>rowOrder;
        vector<int>colOrder;
        queue<int>q;
        for(int i = 1; i <= k; i++){
            if(inDegreeRow[i] == 0){
                q.push(i);
            }
        }
        rowOrder = topologicalSort(graphRow, q, inDegreeRow);
        queue<int>qCol;
        for(int i = 1; i <= k; i++){
            if(inDegreeCol[i] == 0){
                qCol.push(i);
            }
        }
        colOrder = topologicalSort(graphCol, qCol, inDegreeCol);

        if(colOrder.size() < k || rowOrder.size() < k){
            return {};
        }
        // Since we have the order now we have to generate the matrix before that let us handle the edge cases;
        vector<vector<int>>result(k, vector<int>(k, 0));
        for(int i = 0; i < k; i++){
            for(int j = 0; j < k; j++){
                if(rowOrder[i] == colOrder[j]){
                    result[i][j] = rowOrder[i];
                }
            }
        }
        return result;
    }
};
