/*
Explanation:
1. Closest points to origin will have the shortest distance from the origin.
2. So since we need k Closest we need to use heap. If we use minHeap then we can just find out the distance between the points and the origin adn then push in the min heap.
3. Once it is done we can take the top k elements.
4. The T.C is O(N*log(K));
*/
typedef pair<double, vector<int>> p;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        vector<vector<int>>result;
        // priority_queue<vector<int>>maxHeap;
        priority_queue<p , vector<p>, greater<p>>minHeap;

        for(vector<int>&point: points){
            int x = point[0];
            int y = point[1];
            double distance = sqrt(x*x + y*y);
            minHeap.push({distance, point});
            // maxHeap.push({x*x + y*y, x, y});
            // if(maxHeap.size() > k){
            //     maxHeap.pop();
            // }
        }
        // for(int i = 0; i < k; i++){
        //     vector<int>temp = maxHeap.top();
        //     maxHeap.pop();
        //     result[i] = {temp[1], temp[2]};
        // }
        for(int i = 0; i < k; i++){
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;
    }
};
