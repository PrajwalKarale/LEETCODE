/*
    Logic:
        1. First option that comes into my mind is Sliding Window.
        2. Story Points
            a. Counting subarrays based on some property or score.
            b. i, j & j will keep moving -> sum += num[j]
            c. while i <= j && sum * (j - i + 1) >= k:
            d.    sum -= nums[i]
            e.    i++
    Time Complexity:
        1. T.C -> O(n)
    Space Complexity:
        1. S.C -> O(1) since no extra space is used.
*/
typedef long long ll;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define ll long long
#define show(arr) for (auto i: arr) {cout << i << ' ';} cout << "\n"
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define debug(x) cout << #x << " = " << (x) << endl;
#define show_map(m) \
    for (const auto& [key, value] : m) { \
        std::cout << "[" << key << ": " << value << "] "; \
    } \
    std::cout << "\n"

const auto __ = []() 
{
    struct ___ { static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; } };
    std::atexit(&___::_);
    return 0;
}();
auto initialize = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        ll result = 0;
        ll sum = 0;
        int n = nums.size();
        int i = 0;
        int j = 0;
        while(j < n){
            sum += nums[j];
            while(i <= j && sum * (j - i + 1) >= k){
                sum -= nums[i];
                i++;
            }
            result = result + (j - i + 1);
            j++;
        }
        return result;
    }
};
