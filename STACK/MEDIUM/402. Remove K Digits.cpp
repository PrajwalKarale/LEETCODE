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
    string removeKdigits(string num, int k) {
        if(num.length() == k){
            return "0";
        }
        stack<int>s;
        string result = "";
        for(int i = 0; i < num.length(); i++){
            int digit = num[i] - '0';

            while((k > 0) && (!s.empty()) && (s.top() > digit)){
                s.pop();
                k -= 1;
            }

            s.push(digit);
        }
        while(k > 0 && !s.empty()){
            k--;
            s.pop();
        }
        while(!s.empty()){
            char digit = static_cast<char>(s.top() + '0');
            result.push_back(digit);
            s.pop();
        }

        reverse(result.begin(), result.end());
        int i = 0;
        
        while(i < result.length() && result[i] == '0'){
            i++;
        }

        result = result.substr(i);
        return result.empty() ? "0": result;
    }
};
