class Solution {
public:
    int memo[1001];
    int solveByBottomUp(vector<int>&cost){
        int n = cost.size();
        if(n== 2){
            return min(cost[0], cost[1]);
        }
        for(int i = 2; i < n; i++){
            cost[i] = cost[i] + min(cost[i - 1], cost[i - 2]);
        }
        return min(cost[n - 1], cost[n - 2]);
    }
    int solveByMemoization(vector<int>&cost, int i){
        if(i >= cost.size()){
            return 0;
        }
        if(memo[i] != -1){
            return memo[i];
        }
        int step0 = cost[i] + solveByMemoization(cost, i+1);
        int step1 = cost[i] + solveByMemoization(cost, i+2);

        return memo[i] = min(step0, step1);
    }
    int solveByRecursion(vector<int>&cost, int i){
        if(i >= cost.size()){
            return 0;
        }
        int step0 = cost[i] + solveByRecursion(cost, i+1);
        int step1 = cost[i] + solveByRecursion(cost, i+2);
        return min(step0, step1);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        // return min(solveByRecursion(cost, 0), solveByRecursion(cost, 1));
        // memset(memo, -1, sizeof(memo));
        // return min(solveByMemoization(cost, 0),  solveByMemoization(cost, 1));
        return solveByBottomUp(cost);
    }
};
