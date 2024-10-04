auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
};
class Solution {
typedef long long ll;
public:
    int minSubarray(vector<int>& nums, int p) {
        ll n = nums.size();
        ll result = n;
        ll sum = 0;
        for(int i = 0; i < n ; i++){
            sum  = (sum + nums[i]) % p;
        }
        ll target = sum % p;
        if(target == 0){
            return 0;
        }
        unordered_map<ll,ll>mp;
        ll current = 0;
        mp[0] = -1;
        for(int i = 0; i < nums.size(); i++){
            current  = (current + nums[i]) % p;
            int remain = (current - target + p) % p;
            if(mp.find(remain) != mp.end()){
                result = min(result, i - mp[remain]);
            }
            mp[current % p] = i;
        }
        return result == n ? -1 : result;
    }
};
// @lc code=end
