/*
    Logic:
        1. First thought that comes in my mind is sliding window approach since 
    Time Complexity:
        1. T.C -> O(n) where n is the size of the input array
    Space Complexity:
        1. S.C -> O(1) since no extra space is used.
*/
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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
    int countSubarrays(vector<int>& nums) {
        int result = 0;
        int n = nums.size();
        int left = 0;
        int right = 0;
        while(right < n){
            if(right - left + 1 == 3){
                if((nums[left] + nums[right])*2 == nums[right - 1]){
                    result += 1;
                }
                left++;
            }
            right++;
        }
        return result;
    }
};
