class Solution {
public:
    int pivotInteger(int n) {
        if(n == 1){
            return 1;
        }
        int totalSum = 0;
        for(int i = 1; i <= n; i++){
            totalSum += i;
        }
        int prefixSum = 0;
        for(int i = 1; i <= n; i++){
            prefixSum += i;
            if(totalSum - prefixSum + i == prefixSum){
                return i;
            }
        }
        return -1;
    }
};
