class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        long long result = 0;

        // With extra space
        // priority_queue<int> pq;
        // for(int i = 0; i < happiness.size(); i++){
            // pq.push(happiness[i]);
        // }
        // int count = 0;
        // while(k--){
            // int happinesVal = pq.top();
            // pq.pop();
            // result = result + max(happinesVal - count, 0);
            // count++;
        // }

        //Without using extra space
        
        sort(happiness.begin(), happiness.end(), greater<int>());
        for(int i = 0; i < k; i++){
            result = result + max(happiness[i] - i, 0);
        }
        return result;
    }
};
