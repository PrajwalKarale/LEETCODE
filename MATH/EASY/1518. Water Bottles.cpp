class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int bottleConsumed = 0;
        while(numBottles >= numExchange){
            bottleConsumed += numExchange;
            numBottles -= numExchange;
            numBottles += 1;
        }
        return bottleConsumed + numBottles;
    }
};
