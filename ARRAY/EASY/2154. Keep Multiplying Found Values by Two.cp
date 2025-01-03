/*
    Time Complexity:
        1. T.C -> O(n)
    Space Complexity:
        1. S.C -> O(n)
        2. Since we are using auxiliary space to store the elements in set
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int>s(nums.begin(), nums.end());
        bool isFound = true;
        while(isFound){
            if(s.find(original) == s.end()){
                isFound = false;
                break;
            }
            original = original*2;
        }
        return original;
    }
};
