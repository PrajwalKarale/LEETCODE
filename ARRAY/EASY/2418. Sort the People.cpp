#include<execution>

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        vector<string>result;
        vector<pair<int, string>>nameHeight;

        for(int i = 0; i < names.size(); i++){
            nameHeight.push_back({heights[i], names[i]});
        }
        auto lambda = [&nameHeight](pair<int, string>&a, pair<int, string>&b){
            return a.first > b.first;
        };
        sort(execution::par_unseq, nameHeight.begin(), nameHeight.end(), lambda);
        for(auto &it: nameHeight){
            result.push_back(it.second);
        }
        return result;
    }
};
