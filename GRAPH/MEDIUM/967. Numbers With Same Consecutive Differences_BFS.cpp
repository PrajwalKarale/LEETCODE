class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<int>result;

        queue<int>q;
        for(int i = 1; i <= 9; i++){
            q.push(i);
        }
        int level = 1;
        // Since we have already pushed one digit in the queue
        while(!q.empty() && level < n){
            level++;
            int qSize = q.size();
            for(int i = 0; i < qSize; i++){
                int currentNum = q.front();
                q.pop();
                int lastDigit = currentNum % 10;
                if(lastDigit + k <= 9){
                    q.push((currentNum*10 + (lastDigit + k)));
                }
                if(k != 0 && lastDigit - k >= 0){
                    q.push(currentNum*10 + (lastDigit - k));
                }
            }
        }
        while(!q.empty()){
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
};
