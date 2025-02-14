/*
    Logic:
        1. Since they have asked for minimum elements we will be using minimum heap.
        2. Whenever the top element of the heap >= k at that time we can say that all the elements in the heap are greeater than equal to k.
    Time Complexity:
        1. T.C -> O(n * log(n))
        2. Every operation of minHeap takes log(n) time.
    Space Complexity:
        1. S.C -> O(n) since we have used auxiliary space in form of heap.
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
typedef long long ll;
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int result = 0;
        priority_queue<long, vector<long>, greater<long>>minHeap;
        for(int &num: nums){
            minHeap.push(num);
        }
        while(minHeap.size() >= 2 && minHeap.top() < k){
            long x = minHeap.top();
            minHeap.pop();
            long y = minHeap.top();
            minHeap.pop();
            long newElement = (min(x, y) * 2) + max(x, y);
            minHeap.push(newElement);
            result++;
        }
        return result;
    }
};
