/*
    Logic:
    1. Since we need minimum elements we need to create a minimum heap since everytime we will have the smallest element on the top.
    2. Since we have check for marked elements we will save the index of the marked elements in the set which will help us to keep track
    Time Complexity:
        T.C -> O(n * log(n))
    Space Complexity:
        S.C -> O(n) since min heap is created
*/
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   
    cout.tie(nullptr);
};
typedef pair<int,int>pii;
class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score = 0;
        priority_queue<pii, vector<pii>, greater<pii>>minHeap;
        set<int>marked;
        for(int i = 0; i < nums.size(); i++){
            minHeap.push({nums[i], i});
        }
        while(!minHeap.empty()){
            pair<int,int> p = minHeap.top();
            int value = p.first;
            int index = p.second;
            minHeap.pop();
            if(marked.find(index) != marked.end()){
                continue;
            }
            score += value;
            marked.insert(index);
            if(index - 1 >= 0){
                marked.insert(index - 1);
            }
            if(index + 1 < nums.size()){
                marked.insert(index + 1);
            }
        }
        return score;
    }
};
