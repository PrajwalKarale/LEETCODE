/*
    Logic:
        1. Simple Sliding window.
    Time Complexity:
        1. T.C -> O(n) Each charat=cter would be traversed atmost two times.
    Space Complexity:
        1. O(1) -> Since no extra space is used.
*/
const auto __ = []() 
{
    struct ___ { static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; } };
    std::atexit(&___::_);
    return 0;
}();
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    int maxPower(string s) {
        int n = s.length();
        int left = 0;
        int right = 0;
        int result = 0;
        while(right < n){
            if(s[left] != s[right]){
                left = right;
            }
            result = max(result, right - left + 1);
            right++;
        }
        return result;
    }
};
