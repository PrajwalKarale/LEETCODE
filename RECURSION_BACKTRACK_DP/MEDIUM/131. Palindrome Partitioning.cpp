// T.C: Since for each position in a string we check whether to do a partition or not so tota there are 2^n possibilites so O(2^n) also for Palindrome O(n) so time complexity is
// T.C: O(2^n * n)

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
    vector<vector<string>> result;
    bool isPalindrome(string &s, int left, int right){
        while(left < right){
            if(s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    void solve(string &s, vector<string>&curr, int index){
        if(index == s.length()){
            result.push_back(curr);
            return;
        }
        for(int i = index; i < s.length(); i++){
            if(isPalindrome(s, index, i)){
                curr.push_back(s.substr(index, i - index + 1));
                solve(s, curr, i + 1);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>curr;
        solve(s, curr, 0);
        return result;
    }
};
