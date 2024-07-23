#include<algorithm>
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        vector<int>result;
        unordered_map<int,int>freq;
        for(auto &num: nums){
            freq[num]++;
        }
        vector<pair<int,int>>freqNum;
        for(auto it: freq){
            freqNum.push_back({it.first, it.second});
        }
        auto comparator = [](pair<int,int>&a, pair<int,int>&b){
            if(a.second == b.second){
                return a.first > b.first;
            }
            return a.second < b.second;
        };

        sort(freqNum.begin(), freqNum.end(), comparator);
        for(pair<int,int>&it: freqNum){
            for(int i = 0; i < it.second; i++){
                result.push_back(it.first);
            }
        }
        return result;
    }
};
