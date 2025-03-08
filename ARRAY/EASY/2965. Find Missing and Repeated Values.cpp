auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int,int>mp;
        int totalSum = 0;
        vector<int>result;
        int n = grid.size();
        totalSum = (n*n) * ((n*n) + 1) / 2;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                mp[grid[i][j]] += 1;
            }
        }
        int sum = 0;
        for(auto it: mp){
            sum += it.first;
            if(it.second  == 2){
                result.push_back(it.first);
            }
        }
        result.push_back(totalSum - sum);
        return result;
    }
};
