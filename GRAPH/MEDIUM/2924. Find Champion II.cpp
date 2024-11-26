auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int result = -1;
        vector<int>inDegree(n, 0);
        int count = 0;
        if(n == 1){
            return 0;
        }
        for(vector<int>&edge: edges){
            int u = edge[0];
            int v = edge[1];
            inDegree[v]++;
        }
        for(int i = 0; i < n; i++){
            if(inDegree[i] == 0){
                count++;
                result = i;
            }
        }
        return count > 1 ? -1: result;
    }
};
