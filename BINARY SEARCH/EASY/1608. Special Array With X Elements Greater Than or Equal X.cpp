//T.C -> O(n * log(n))

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
    int specialArray(vector<int>& nums) {
        int left = 1;
        int right = nums.size();
        while(left <= right){
            int count = 0;
            int x = left + (right - left) / 2;
            cout << left << " " << right << " " << x << endl;
            for(int &num: nums){
                if(num >= x){
                    count++;
                }
            }
            if(count == x){
                return x;
            }
            if(count > x){
                left = x + 1;
            }else{
                right = x - 1;
            }
        }
        return -1;
    }
};
