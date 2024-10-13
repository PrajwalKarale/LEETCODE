/*
    Time Complexity:
        1. Since n is the number of elements in the array
        2. T.C -> O(n)
    Space Complexity:
        1. We are creating a vector which consists of remainder only from 0 to 60
        2. S.C -> O(60) which is a constant space
*/
#pragma GCC optmize ("O12")
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    typedef long long ll;
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        vector<ll>remainder(60);
        for(int i = 0; i < n; i++){
            remainder[time[i] % 60]++;
        }
        ll result = 0;
        result += (ll)(remainder[0] * (remainder[0] - 1)) / 2;
        result += (ll)(remainder[30] * (remainder[30] - 1)) / 2;
        for(int i = 1; i <= 29; i++){
            result = result + (ll)(remainder[i] * remainder[60 - i]);
        }
        return (int)result;
    }
};
