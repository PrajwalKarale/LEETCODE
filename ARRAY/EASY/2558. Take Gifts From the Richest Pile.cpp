/*
    Logic:
        Each Time we have to choose the maximum number of gifts so we would be using max Heap so that we get max everytime
    Time Complexity:
        T.C -> O(n*log(n))
        Since we are pushing n elements in the maximum heap and pushing operation in a maximum heap takes log(n) time
    Space Complexity:
        S.C -> O(n)
        Priority queue is created.
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>maxHeap;
        for(int &gift: gifts){
            maxHeap.push(gift);
        }
        while(k--){
            int giftAtTop = maxHeap.top();
            maxHeap.pop();
            maxHeap.push(sqrt(giftAtTop));
        }
        long long answer = 0;
        while(!maxHeap.empty()){
            answer = answer + maxHeap.top();
            maxHeap.pop();
        }
        return answer;
    }
};
