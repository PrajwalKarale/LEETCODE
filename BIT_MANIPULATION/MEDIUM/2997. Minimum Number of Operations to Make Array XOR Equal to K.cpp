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
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        for(int bitPosition = 0; bitPosition <= 20; bitPosition++){
            int xorValue = 0;
            for(int num: nums){
                int bitValue = (1 << bitPosition) & num;
                xorValue = xorValue ^ bitValue;
            }
            int kBitValue = (1 << bitPosition) & k;
            if(kBitValue != xorValue){
                ans++;
            }
        }
        return ans;
    }
};
