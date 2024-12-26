/*
    Logic:
        1. One approach is once you buy a stock and then you will iterate through the array to find an appropriate selling price. Downside of this aproach is that we iterate the array too many times
        2. Second approach is only buy the stock when its price is less than the last purchased price.
    Time Complexity:
        1. T.C -> O(n)
    Space Complexity:
        1. S.C -> O(1)
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maximumProfit = 0;
        int buyPrice = prices[0];
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] < buyPrice){
                buyPrice = prices[i];
            }else{
                int currentProfit = prices[i] - buyPrice;
                maximumProfit = max(maximumProfit, currentProfit);
            }
        }
        return maximumProfit;
    }
};
