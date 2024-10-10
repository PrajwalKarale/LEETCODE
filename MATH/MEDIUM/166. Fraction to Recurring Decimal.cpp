/*
    Time Complexity:
        1. The loop will run for log(n) times where n is the number of digits in numerator or denominator
        2. T.C -> O(log(n))
    Space Complexity:
        1. Map is created to store the remainders since the number of remainders store would be at most equal to the number of digits which will be log(n) where n is the number of digits
        2. S.C -> O(log(n))
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
typedef long long ll;
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0){
            return "0";
        }
        string ans = "";
        if(numerator < 0 ^ denominator < 0){
            ans = ans + "-";
        }
        ll numerator1 = abs((ll)numerator);
        ll denominator1 = abs((ll)denominator);
        ll quotient = numerator1 / denominator1;
        ll remainder = numerator1 % denominator1;
        ans = ans + to_string(quotient);
        if(remainder == 0){
            return ans;
        }
        ans = ans + '.';
        unordered_map<ll, int>mp;
        while(remainder != 0){
            if(mp.find(remainder) != mp.end()){
                int position = mp[remainder];
                ans.insert(position, "(");
                ans = ans + ')';
                break;
            }else{
                mp[remainder] = ans.length();
                remainder = remainder * 10;
                quotient = remainder / denominator1;
                remainder = remainder % denominator1;
                ans = ans + to_string(quotient);
            }
        }
        return ans;
    }
};
// @lc code=end
