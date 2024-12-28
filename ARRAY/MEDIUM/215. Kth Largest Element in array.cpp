/*
    Logic:
        1. Since we were jnot allowed to sort we need to find a data structure that will keep the maximum element on top always so we used max heap.
    Time Complexity:
        1. The pushing in mac heap takes log(n) time hence T.C -> O(n * log(n))
    Space Complexity:
        1. We have use priority_queue so S.C -> O(n)
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int result = 0;
        priority_queue<int>maxHeap;
        for(int &num: nums){
            maxHeap.push(num);
        }
        while(k--){
            result = maxHeap.top();
            maxHeap.pop();
        }
        return result;
    }
};
