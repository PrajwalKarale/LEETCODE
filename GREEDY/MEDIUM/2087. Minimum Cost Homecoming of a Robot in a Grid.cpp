/*
    Time Complexity:
        1. T.C -> O(n + m) where n = rowCosts.length and m = colCosts.length
    Space Complexity:
        2. S.C -> O(1)

*/
#pragma GCC optmize ("O12")
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};

class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int startX = startPos[0];
        int startY = startPos[1];
        int homeX = homePos[0];
        int homeY = homePos[1];
        int cost = 0;

        // Since the start position and destination position are equal
        if(startX == homeX && startY == homeY){
            return 0;
        }
        if(homeX > startX){
            while(homeX != startX){
                startX += 1;
                cost += rowCosts[startX];
            }
        }else{
            while(homeX != startX){
                startX -= 1;
                cost += rowCosts[startX];
            }
        }
        if(homeY > startY){
            while(startY != homeY){
                startY += 1;
                cost += colCosts[startY];
            }
        }else{
            while(startY != homeY){
                startY -= 1;
                cost += colCosts[startY];
            }
        }
        return cost;
    }
};
