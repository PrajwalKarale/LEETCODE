/*
    Logic:
        1. Chossing an element which doesnt lie in banned
        2. Subtracting it from maxSum
        3. when masXum < 0 that means we have found the mximum count
        4. Used set so that the serch operation is faster we can do binary search instead of set data structure
    Time Complexity:
        1. We are vising each and every element from 1 to N
        2. T.C -> o(n)
    Space Complexity:
        1. We are creating a set of banned elements
        2. s.C -> O(len(banned))
*/

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int>s(banned.begin(), banned.end());
        int result = 0;
        for(int i = 1; i <= n; ++i){
            if(s.find(i) != s.end()){
                continue;
            }
            maxSum -= i;
            if(maxSum < 0){
                break;
            }
            result += 1;
        }
        return result;
    }
};
