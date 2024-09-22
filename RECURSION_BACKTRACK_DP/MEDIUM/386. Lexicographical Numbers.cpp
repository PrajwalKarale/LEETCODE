/*
    1.Time Complexity:
        O(n): Since we have visited each and every digit from 1 to n
    2. Space Complexity:
        O(number of digits) -> O(log(n))
*/
class Solution {
public:
    void solve(vector<int>&result, int currentNum, int n){
        if(currentNum > n){
            return ;
        }
        result.push_back(currentNum);
        for(int j = 0; j <= 9; j++){
            int newNum = (currentNum * 10) + j;
            if(newNum > n){
                return;
            }
            solve(result, newNum, n);
        }
    }
    vector<int> lexicalOrder(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<int>result;
        for(int i = 1; i <= 9; i++){
            solve(result, i, n);
        }
        return result;
    }
};
