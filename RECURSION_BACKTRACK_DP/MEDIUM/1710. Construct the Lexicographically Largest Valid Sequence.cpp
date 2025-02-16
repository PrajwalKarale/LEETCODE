/*
    Logic:
        1. Since we can see that constraint is 1 <= n <= 20 we know that it is an recursion problem and also there can be multiple outputs and from that we have to find the lexicographically largest.
        2. The resultant vector will have size (2*n) - 1. Now since we want lexicographically largest we will start filling the vector with the largest number.
        3. We need to maintain a set called `used` which will contain the numbers that we have used.
        4. For any index we will try to put largest number first, if not possible we will put 2nd largest index and so on. Which means that we have to explore different options.
    Time Complexity:
        1. For each index we have n possibilites. So if we place one number of index i then on next index it has n-1 possibilites.
        2. T.C -> O(n!)
    Space Complexity:
        1. We have used `used` as an auxiliary space.
        2. S.C -> O(n)
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    bool solve(int i, int n, vector<int>&result, unordered_set<int>&used){
        if(i >= result.size()){
            return true;
        }
        // If result[i] is already assigned number
        if(result[i] != -1){
            return solve(i+1, n, result, used);
        }
        for(int num = n; num >= 1; num--){
            if(used.find(num) != used.end()){
                continue;
            }
            //Try
            used.insert(num);
            result[i] = num;

            //Explore
            if(num == 1){
                if(solve(i+1, n, result, used) == true){
                    return true;
                }
            }else{
                int j = result[i] + i;
                if(j < result.size() && result[j] == -1){
                    result[j] = num;
                    if(solve(i+1, n, result, used) == true){
                        return true;
                    }
                    result[j] = -1;
                }
            }
            //Backtrack
            used.erase(num);
            result[i] = -1;
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int>result((2*n) - 1, -1);
        unordered_set<int>used;
        solve(0, n, result, used);
        return result;
    }
};
