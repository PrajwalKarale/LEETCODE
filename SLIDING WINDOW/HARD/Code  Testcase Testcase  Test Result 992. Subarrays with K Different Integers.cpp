// Since we are applying Sliding Window technique twice T.C -> O(n)
// We are using unordered_map as an extraa space. Hence The S.C -> O(n)

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

class Solution {

public:
Solution(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
    int slidingWindow(vector<int>&nums, int k){
        unordered_map<int,int> freq;
        int i = 0;
        int j = 0;
        int n = nums.size();
        int result = 0;
        while(j < n){
            freq[nums[j]]++;
            while(freq.size() > k){
                freq[nums[i]]--;
                if(freq[nums[i]] == 0){
                    freq.erase(nums[i]);
                }

                i++;
            }
            result = result + (j - i + 1);
            j++;
        }
        return result;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return slidingWindow(nums, k) - slidingWindow(nums, k - 1);
    }
};
