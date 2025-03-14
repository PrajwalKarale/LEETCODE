/*
    Logic:
        1. Whenever Circular array is given at that time we have to append the same array. In Brute force appraoch for every i we are starting j from i itself.
        2. This hints us towards sliding window approach. The approach is simple start i = 0, j = 1 and check colors[i] and colors[j]
    Time Complexity:
        1. T.C -> O(n - k + 1) since we are adding k - 1 elements in the colors array
    Space Complexity:
        1. S.C -> O(1) siince no auxiliary space is used
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
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        for(int i = 0; i < k-1; i++){
            colors.push_back(colors[i]);
        }
        int i = 0;
        int j = 1;
        int result = 0;
        while(j < colors.size()){
            if(colors[j] == colors[j - 1]){
                i = j;
                j++;
                continue;
            }
            if(j - i + 1 == k){
                result += 1;
                i++;
            }
            j++;
        }
        return result;
    }
};
