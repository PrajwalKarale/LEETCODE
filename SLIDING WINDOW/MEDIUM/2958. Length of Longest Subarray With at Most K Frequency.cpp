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

auto initialize = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>frequency;
        
        int i = 0;
        int j = 0;
        int result = 0;
        while(j < n){
            frequency[nums[j]]++;
            while(frequency[nums[j]] > k && i < j){
                frequency[nums[i]]--;
                i++;
            }
            result = max(result, j - i + 1);
            j++;
        }
        return result;
    }
};
