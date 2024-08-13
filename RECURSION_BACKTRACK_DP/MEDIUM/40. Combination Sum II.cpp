/*
T.C -> O(2^N) since for every element we have options whether to take or not take hence exponential ime function
S.C -> O(N) since curr is used
*/

class Solution {
public:
    vector<vector<int>>result;
    void solve(vector<int>& candidates, int target, vector<int>&curr, int index){
        if(target < 0){
            return;
        }
        if(target == 0){
            result.push_back(curr);
            return;
        }
        for(int i = index; i < candidates.size(); i++){
            if(i > index && candidates[i] == candidates[i - 1]){
                continue;
            }
            curr.push_back(candidates[i]);
            solve(candidates, target - candidates[i], curr, i + 1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        sort(candidates.begin(), candidates.end());
        vector<int>curr;
        solve(candidates, target, curr, 0);
        return result;
    }
};
