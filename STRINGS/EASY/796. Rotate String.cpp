/*
    Time Complexity:
        1. T.C -> O(n)
    Space Complexity:
        2. S.C -> O(n)
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    bool rotateString(string s, string goal) {
        string newS = s + s;
        if(newS.contains(goal) && s.length() == goal.length()){
            return true;
        }     
        return false;
    }
};
