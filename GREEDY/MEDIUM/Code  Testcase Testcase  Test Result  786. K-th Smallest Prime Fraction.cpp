typedef pair<float, pair<int,int>> t;
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<int>result;
        priority_queue<t, vector<t>, greater<t>>minHeap;
        for(int i = 0; i < arr.size(); i++){
            for(int j = i + 1; j < arr.size(); j++){
                float fraction = static_cast<float>(arr[i])/arr[j];
                minHeap.push({fraction, {i,j}});
            }
        }
        for(int i = 0; i < k - 1; i++){
            minHeap.pop();
        }
        pair<int,int> indices = minHeap.top().second;
        result.push_back(arr[indices.first]);
        result.push_back(arr[indices.second]);
        return result;
    }
};
