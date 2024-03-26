class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
       int smallest = INT_MAX;
       map<int,int> freq;
       for(int i = 0; i < nums.size(); i++){
            if(nums[i] < INT_MAX){
                smallest = nums[i];
            }
            freq[nums[i]]++;
       }
       bool it = true;
       int start = 1;
       int result = 0;
       while(it){
        if(freq.find(start) == freq.end()){
            result = start;
            it = false;
        }
        start++;
       }
        return result;
    }
};
