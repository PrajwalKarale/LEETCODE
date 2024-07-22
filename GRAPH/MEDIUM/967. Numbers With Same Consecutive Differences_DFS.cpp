class Solution {
public:
    void dfs(int num, int n, int k, vector<int>&result){
        if(n == 0){
            result.push_back(num);
            return;
        }
        int currentDigit = num % 10;
        if(currentDigit + k <= 9){
            dfs(((num * 10) + (currentDigit + k)), n - 1, k, result);
        }
        // k != 0 is the edge case condition
        if(k != 0 && currentDigit - k >= 0){
            dfs((num*10) + (currentDigit - k), n - 1, k, result);
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        vector<int>result;

        for(int i = 1; i <= 9; i++){
            // Since one digit is already used we are passing n-1
            dfs(i, n-1, k, result);
        }
        return result;
    }
};
