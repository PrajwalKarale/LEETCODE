/*
    Logic:
        1. We have to find the maximum element in a given window. First thought is traverse all the windows and the traverse to find the maximum element. But it is not optimal
        2. There should be something that the maximum element should be easily available. In this case we are using monotnmic deque so that the maximum element of the window is available in the front.
    Time Complexity:
        1. We are visiting every element in the array once
        2. T.C -> O(n)
    Space Complexity:
        1. We have use deque to store the indexes of the element
        2. S.C -> O(n)
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>result;
        if(nums.size() == 1){
            return nums;
        }
        int n = nums.size();
        deque<int>d;
        for(int i = 0; i < n; i++){
            while(!d.empty() && d.front() <= i - k){
                d.pop_front();
            }
            while(!d.empty() && nums[i] > nums[d.back()]){
                d.pop_back();    
            }
            d.push_back(i);
            if(i >= k - 1){
                result.push_back(nums[d.front()]);
            }
        }
        return result;
    }
};
