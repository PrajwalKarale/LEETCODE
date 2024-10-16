auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
};
class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int n = s.length();
        vector<int>overallShifts(2,0);
        for(vector<int>&shi: shift){
            overallShifts[shi[0]] += shi[1];
        }
        int leftShift = overallShifts[0];
        int rightShift = overallShifts[1];
        if(leftShift > rightShift){
            int shifts = (leftShift - rightShift) % n;
            s = s.substr(shifts) + s.substr(0, shifts);
        }else{
            int shifts = (rightShift - leftShift) % n;
            s = s.substr(n - shifts) + s.substr(0, n - shifts);
        }
        return s;
    }
};
