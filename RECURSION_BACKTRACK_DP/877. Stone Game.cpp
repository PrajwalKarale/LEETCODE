/*
    Logic:
        1. We are playing with respect to Alice. Similar to 486. Predict the Winner 
    Time Complexity:
        1. solveByRecursion
            a. Since a each moment we have two choices so the T.C -> O(2^n)
        2. solveByMemoization
            a. We are filling 2D array.
            b. T.C -> O(n^2)
    Space Complexity:
        1. solveByRecursion
            a. Recursion call is taking stack space
            b. S.C -> O(n) which is a stack space in the memory
        2. solveByMemoization
            a. S.C -> O(n^2) since we are taking an 2D array.
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    int solve(vector<int>&piles, int i, int j){
        if(i > j){
            return 0;
        }
        int takeI = piles[i] + min(
            solve(piles, i + 2, j),
            solve(piles, i + 1, j - 1)
        );
        int takeJ = piles[j] + min(
            solve(piles, i + 1, j - 1),
            solve(piles, i, j - 2)
        );
        return max(takeI, takeJ);
    }
    bool solveByRecursion(vector<int>&piles){
        int totalStones = 0;
        int n = piles.size();
        for(int &pile: piles){
            totalStones += pile;
        }
        int alice = solve(piles,0, n - 1);
        int bob = totalStones - alice;
        return alice >= bob;
    }
    int memoize(vector<int>&piles, int i, int j, vector<vector<int>>&memo){
        if(i > j){
            return 0;
        }
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        int takeI = piles[i] + min(
            memoize(piles, i + 2, j, memo),
            memoize(piles, i + 1, j - 1, memo)
        );
        int takeJ = piles[j] + min(
            memoize(piles, i + 1, j - 1, memo),
            memoize(piles, i, j - 2, memo)
        );
        return memo[i][j] = max(takeI, takeJ);
    }
    bool solveByMemoization(vector<int> &piles){
        vector<vector<int>>memo(503, vector<int>(503, -1));
        int totalStones = 0;
        int n = piles.size();
        for(int &pile: piles){
            totalStones += pile;
        }
        int alice = memoize(piles,0, n - 1, memo);
        int bob = totalStones - alice;
        return alice >= bob;
    }
    bool stoneGame(vector<int>& piles) {
        // return solveByRecursion(piles);
        return solveByMemoization(piles);
    }
};
