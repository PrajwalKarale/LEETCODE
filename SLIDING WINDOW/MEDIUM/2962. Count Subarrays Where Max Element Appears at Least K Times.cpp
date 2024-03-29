// Since in this method we are only traversing each element once so the T.C -> O(n)
// We have not used any extra space the S.C -> O(1)

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
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxEle = INT_MIN;
        int countOfMax = 0;
        long long result = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] > maxEle){
                maxEle = max(maxEle, nums[i]);
            }
        }
        int i = 0;
        int j = 0;
        while(j < n){
            if(nums[j] == maxEle){
                countOfMax++;
            }
            while(countOfMax >= k){
                result += n - j;
                if(nums[i] == maxEle){
                    countOfMax--;
                }
                i++;
            }
            j++;
        }
        return result;
    }
};
