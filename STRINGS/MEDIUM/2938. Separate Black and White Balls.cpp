/*
    Time Complexity:
        1. T.C -> O(n) where n is the length of the stringf
    Space Complexity:
        1. S.C -> O(1) since no extra spaced is used
*/
#pragma GCC optmize ("O12")
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
};
class Solution {
    typedef long long ll;
public:
    long long minimumSteps(string s) {
        ll swaps = 0;
        ll blackBallCount = 0;
        for(char &ch: s){
            if(ch == '1'){
                blackBallCount += 1;
            }else{
                swaps += blackBallCount;
            }
        }
        return swaps;
    }
};
