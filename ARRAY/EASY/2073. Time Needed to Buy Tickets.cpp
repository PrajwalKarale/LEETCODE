#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

auto initialize = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int time = 0;
        for(int i = 0; i < n; i++){
            // if the person is front of the desired person
            if(i <= k){
                time += min(tickets[i], tickets[k]);
            }else{
                // if the person is behind the kth person that means the kth person has already bought the ticket
                // That means if the kth person has to buy 1 ticket that means the person behind him should not buy
                time += min(tickets[i], tickets[k] - 1);
            }
        }
        return time;  
    }
};
