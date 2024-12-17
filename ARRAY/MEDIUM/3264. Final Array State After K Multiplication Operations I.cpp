/*
    Logic:
        1. Since everytime we have to pick the minimum element we have to create a minHeap.
    Time Complexity:
        1. T.C -> O(n * log(n)) + O(k * log(n))
        2. Since we have to push elements in the minHeap which takes log(n) operation
    Space Complexity:
        1. S.C -> O(n) since minHeap is created and all the elements are stored.
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    typedef pair<int,int>pii;
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pii, vector<pii>, greater<pii>>minHeap;
        for(int i = 0; i < nums.size(); i++){
            minHeap.push({nums[i], i});
        }
        while(k--){
            auto it = minHeap.top();
            minHeap.pop();
            nums[it.second] = multiplier * it.first;
            minHeap.push({multiplier * it.first, it.second});
        }
        return nums;
    }
};
