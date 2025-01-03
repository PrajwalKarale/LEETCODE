/*
    Logic:
        Approach1:
            1. Create a vector and then add the element sort the vector since we need to find the median.
            2. This approach would take TLE since we are sorting after adding each element. We need to avoid sorting hence we need to think of something else
        Approach 2:
            1. Since we need to avoid sorting what if we use maxHeap and minHeap to keep the recently added elements on the top.
            2. For even length array the median is mean of mid two elements and for odd length array median is the middle element.
            3. If there are odd elements then the top element of the maxHeap would be the median.
            4. For even length array since the median is the mean of center two elements that means there must be a way to access those elements in O(1) time. Hence we are using priority_queue
            
    Time Complexity:
    
    Space Complexity:
        1. We have created two priority queue as auxiliary space.
        2. S.C -> O(n)
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);    
};
class MedianFinder {
public:
    priority_queue<int>maxHeap;
    priority_queue<int, vector<int>, greater<int>>minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.empty() || num < maxHeap.top()){
            maxHeap.push(num);
        } else{
            minHeap.push(num);
        }
        if(abs((int)maxHeap.size() - (int)minHeap.size()) > 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }else if(minHeap.size() > maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size() == minHeap.size()){
            double mean = (maxHeap.top() + minHeap.top()) / 2.0;
            return mean;
        }
        return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
