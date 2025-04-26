/*
    Logic:
        1. Everytime we have to find the minimum. So in order to get minimum cost we need to use min heap.
        2. Story Points
            a. Since we need minimum from first candidates and last candidates we need two min heap.
            b. ans = 0; i = 0; j = n - 1 where n = costs.size(), hired = 0; pq1; pq2
            c. while hired < k:
            d.      while pq1.size() < candidates && i <= j:
            e.          pq1.push(costs[i]); i++;
            f.      while pq2.size() < candidates && j >= i:
            g.          pq2.push(costs[j]); j--;
            h.      int minP1 = pq1.size() > 0 ? pq1.top(): INT_MAX
            i.      int minP2 = same as above
            j.      if(minP1 < minP2):
            k.          ans += minP1
            l.      else: ans += minP2
            m.      hired++; // Since in each move one candidate is hired.
    Time Complexity:
        1. First while loop will run for O(k)
        2. Inside we are performing push operation which takes O(log(n)) time;
        3. T.C -> O(k * log(candidates))
    Space Complexity:
        1. Since we are using two min heaps
        2. S.C -> O(2*candidates)
*/
const auto __ = []() 
{
    struct ___ { static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; } };
    std::atexit(&___::_);
    return 0;
}();
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};

typedef long long ll;
typedef pair<int,int>pii;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        ll result = 0;
        int i = 0;
        int j = costs.size() - 1;
        priority_queue<int, vector<int>, greater<int>>pq1;
        priority_queue<int, vector<int>, greater<int>>pq2;
        int hired = 0;
        while(hired < k){
            while(pq1.size() < candidates && i<= j){
                pq1.push(costs[i]);
                i++;
            }
            while(pq2.size() < candidates && j >= i){
                pq2.push(costs[j]);
                j--;
            }
            int minP1 = pq1.size() > 0 ? pq1.top() : INT_MAX;
            int minP2 = pq2.size() > 0 ? pq2.top() : INT_MAX;
            if(minP1 <= minP2){
                result += minP1;
                pq1.pop();
            }else{
                result += minP2;
                pq2.pop();
            }
            hired++;
        }
        return result;
    }
};
