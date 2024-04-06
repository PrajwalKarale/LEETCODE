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
    vector<string> buildArray(vector<int>& target, int n) {
        int tSize = target.size();
        int i = 0; 
        vector<string> result;
        int stream = 1;
        while(i < tSize && stream <= n){
            result.push_back("Push");
            if(target[i] == stream){
                i++;
            }else{
                result.push_back("Pop");
            }
            stream++;
        }
        return result;
    }
};
