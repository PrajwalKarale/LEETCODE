/*
T.C -> O(n). This is the time complexity required for the finding the sum
*/
class Solution {
    typedef long long ll;
public:
    int mod = 1e9+7;
    int chalkReplacer(vector<int>& chalk, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n = chalk.size();
        ll totalChalkForOneCycle = 0;
        for(int &c: chalk){
            totalChalkForOneCycle += c;
        }
        k = k % totalChalkForOneCycle;
        for(int i = 0; i < n; i++){
            if(chalk[i] > k){
                return i;
            }
            k -= chalk[i];
        }
        return -1;
    }
};
