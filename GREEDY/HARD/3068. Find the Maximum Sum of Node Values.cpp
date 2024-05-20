// T.C -> O(n); Since we travel one element at once.
// S.C -> O(1);

auto speedUp = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

#pragma GCC optimize("Ofast")
#pragma GCC target("tune=native")

class Solution {
public:
    typedef long long ll;
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll sum = 0;
        int count = 0;
        int minimumLoss = INT_MAX;
        for(ll num: nums){
            if((num ^ k) > num){
                count += 1;
                sum += (num ^ k);
            }else{
                sum += num;
            }
            minimumLoss = min((long long)minimumLoss, abs(num - (num ^ k)));
        }
        if(count % 2 == 0){
            return sum;
        }
        return sum - minimumLoss;
    }
};
