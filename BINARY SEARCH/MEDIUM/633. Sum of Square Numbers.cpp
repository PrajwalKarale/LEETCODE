class Solution {
public:
    bool judgeSquareSum(int c) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        long left = 1;
        long right = sqrt(c);
        if(right * right == c){
            return true;
        }
        while(left <= right){
            long sum = (left * left) + (right * right);
            if(sum == c){
                return true;
            }else if(sum > c){
                right--;
            }else{
                left++;
            }
        }
        return false;
    }
};
