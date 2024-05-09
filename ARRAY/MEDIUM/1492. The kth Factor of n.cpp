class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> divisors;
        for(int i = 1; i <= n; i++){
            if(n % i == 0){
                divisors.push_back(i);
            }
        }
        if(k > divisors.size()){
            return -1;
        }
        return divisors[k - 1];
    }
};
