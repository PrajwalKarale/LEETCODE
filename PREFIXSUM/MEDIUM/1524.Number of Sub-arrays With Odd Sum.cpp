/*
    Logic:
        1. Even + Odd = Odd
        2. Odd + Even = Odd
        3. Even & Odd Count Tracking:
            a. Maintain counts of even and odd prefix sums encountered so far.
            b. If current prefix sum is even, add count of previous odd prefix sums to the result.
            c. If odd, add count of previous even prefix sums to the result.
    Time Complexity:
        1. T.C -> O(n)
    Space Complexity:
        1. We are using auxiliary vector to store the prefix sum
        2. S.C -> O(n)
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
    int mod = 1e9 + 7;
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int>prefixSum(n,0);
        prefixSum[0] = arr[0];
        for(int i = 1; i < n; i++){
            prefixSum[i] = prefixSum[i - 1] + arr[i];
        }
        int evenCount = 1;
        int oddCount = 0;
        int result = 0;
        for(int i = 0; i < n; i++){
            if(prefixSum[i] % 2 == 0){
                //if even prefix sum is encountered
                result = (result + oddCount) % mod;
                evenCount++;
            }else{
                // odd prefix Sum is encountered
                result = (result + evenCount) % mod;
                oddCount++;
            }
        }
        return result;
    }
};
