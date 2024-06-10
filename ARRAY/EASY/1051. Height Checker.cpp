auto initialize = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> temp = heights;
        sort(heights.begin(), heights.end());
        int result = 0;
        for(int i = 0; i < heights.size(); i++){
            if(heights[i] != temp[i]){
                result++;
            }
        }
        return result;
    }
};
