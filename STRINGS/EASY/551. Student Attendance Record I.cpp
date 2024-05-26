#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

auto initialize = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool checkRecord(string s) {
        int absent = 0;
        int late = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'A'){
                absent++;
            }
            if(s[i] == 'L'){
                late++;
            }else{
                late = 0;
            }
            if(absent >= 2 || late > 2){
                return false;
            }
        }
        return true;
    }
};
