#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define ll long long
#define endl "\n"
#define show(arr) for (auto i: arr) {cout << i << ' ';} cout << "\n"
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define debug(x) cout << #x << " = " << (x) << endl;

auto initialize = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        if(k <= 1){
            return 0;
        }
        int n = nums.size();
        int result = 0;
        int i = 0;
        int j = 0;
        int product = 1;
        while(j < n){
            product *= nums[j];
            while(product >= k){
                product = product / nums[i];
                i++;
            }
            result = result + (j - i + 1);
            j++;
        }
        return result;
    }
};
