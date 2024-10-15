auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
    typedef long long ll;
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<ll>maxHeap;
        int n = nums.size();

        for(int &num: nums){
            maxHeap.push(num);
        }
        ll result = 0;
        while(k > 0){
            ll element = maxHeap.top();
            maxHeap.pop();
            result += element;
            element = ceil((double)element / 3);
            maxHeap.push(element);
            k--;
        }
        return result;
    }
};
