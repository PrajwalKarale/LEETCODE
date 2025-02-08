/*
    Logic:
    Time Complexity:
        1. TC -> O(n) where n is the total number of queries.
    Space Complexity:
        1. SC -> O(n) where n is the total number of balls.
        2. We have used ausiliary space which consists of two maps and one set
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int>result;
        unordered_map<int,int>ballColor;
        unordered_map<int, int>colorCount;
        unordered_set<int>colors;
        for(auto &query: queries){
            int ballNumber = query[0];
            int color = query[1];
            if(ballColor.find(ballNumber) != ballColor.end()){
                int currentColor = ballColor[ballNumber];
                colorCount[currentColor]--;
                if(colorCount[currentColor] == 0){
                    colors.erase(currentColor);
                }
            }
            ballColor[ballNumber] = color;
            colorCount[color]++;
            colors.insert(color);
            result.push_back(colors.size());
        }
        return result;
    }
};
