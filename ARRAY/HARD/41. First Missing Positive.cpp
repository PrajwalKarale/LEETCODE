class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int n = nums.size();
        bool isOne = false;
        for(int i = 0; i < n; i++){
            //Checking whether 1 is present in array or not
            if(nums[i] == 1){
                isOne = true;
            }
            //If nums[i] <= 0 or nums[i] > n we have to convert it into 1
            if(nums[i] <= 0 || nums[i] > n){
                nums[i] = 1;
            }
        }
        if(isOne == false){
            return 1;
        }
        for(int i = 0; i < n; i++){
            int indexOfEle = abs(nums[i]) - 1;
            if(nums[indexOfEle] < 0){
                continue;
            }
            nums[indexOfEle] = -1 * nums[indexOfEle];
        }
        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                return i + 1;
            }
        }
        return n + 1;
    }
};
