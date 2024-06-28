class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<int>inDegree(n);
        for(vector<int>&road: roads){
            inDegree[road[0]]++;
            inDegree[road[1]]++;
        }
        vector<pair<int,int>>citiesDegree;
        for(int i = 0; i < n; i++){
            citiesDegree.push_back({inDegree[i], i});
        }
        sort(citiesDegree.begin(), citiesDegree.end(), greater<pair<int,int>>());
        vector<int>importance(n);
        for(int i = 0; i < n; i++){
            importance[citiesDegree[i].second] = n - i;
        }
        long long result = 0;
        for(auto &road: roads){
            result += importance[road[0]] + importance[road[1]];
        }
        return result;
    }
};
