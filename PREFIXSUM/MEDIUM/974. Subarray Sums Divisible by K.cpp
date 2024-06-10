auto initialize = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>remCount;
        int result = 0;
        int sum = 0;
        // If the input contains just one element
        if(nums.size() == 1 && nums[0] % k != 0){
            return 0;
        }
        remCount[0] = 1;
        for(int i = 0; i < nums.size(); i++){
           sum += nums[i];
           int remainder = sum % k;
           if(remainder < 0){
            remainder = remainder + k;
           }
           // If the remainder is already seen in the map that means we have already encountere it
           // before which means the s1-s2 is multiple of k
           if(remCount.find(remainder) != remCount.end()){
                result = result + remCount[remainder];
                remCount[remainder]++;
           }else{
            remCount[remainder]++;
           }
        }
        return result;
    }
};
