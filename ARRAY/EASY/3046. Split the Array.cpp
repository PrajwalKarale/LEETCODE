auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]] += 1;
        }
        for(auto it: freq){
            if(it.second > 2){
                return false;
            }
        }
        return true;
    }
};
