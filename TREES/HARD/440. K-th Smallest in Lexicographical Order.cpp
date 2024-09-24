/*
 * @lc app=leetcode id=440 lang=cpp
 *
 * [440] K-th Smallest in Lexicographical Order
 */

// @lc code=start
/*
    Time Complexity:
        1. O(log n) where log n represents the number of digits in n.
        2. countNumbers also takes log n
        2. T.C -> O(log n * log n) -> O(log n ^ 2)
    Space Complexity:
        1. S.C -> O(1)
*/
class Solution {
typedef long long ll;
public:
    int countNumbers(ll curr, ll next, int n){
        ll num = 0;
        while(curr <= n){
            num = num + (next - curr);
            curr *= 10;
            next *= 10;
            next = min(next, ll(n + 1));
        }
        return num;
    }
    int findKthNumber(int n, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int current = 1;
        k -= 1;
        while(k > 0){
            int numbersInGap = countNumbers(current, current + 1, n);
            if(numbersInGap <= k){
                current++;
                k -= numbersInGap;
            }else{
                // Go Deeper in height
                current *= 10;
                k -= 1;
            }
        }
        return current;
    }
};
// @lc code=end
