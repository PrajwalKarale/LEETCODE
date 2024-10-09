auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
};
class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        vector<vector<int>> result;
        map<int,vector<int>> freq;
        for(vector<int> &item: items){
            int id = item[0];
            int score = item[1];
            freq[id].push_back(score);
        }
        for(auto it: freq){
            int average = 0;
            sort(it.second.begin(), it.second.end(), greater<int>());
            for(int i = 0; i < 5; i++){
                average = average + it.second[i];
            }
            result.push_back({it.first, average / 5});
        }
        return result;
    }
};
