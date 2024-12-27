/*
    Logic:
        1. Brute force loginv is sdtright forward
        2. values[i] + values[j] + i - j = (values[i] + i) + (values[j] - j) this tell us that x + y will be maximum for a certain amount of y if x is maximum. That means we have to set values[i] + i to be as maximum as possible
    Time Complexity:
        1. Bruteforce will take T.C -> O(n^2)
        2. Optimised appraqoch will take T.C -> O(2*n)
    Space Complexity:
        1. BruteForce will take S.C -> O(1)
        2. In Optimised approach we are creating a vector that will store the value of the maximum value so S.C. -> O(n)
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    int bruteForce(vector<int>&values){
        int n = values.size();
        int maxScore = 0;
        for(int i = 0; i < n-1; i++){
            for(int j = i + 1; j < n; j++){
                maxScore = max(maxScore, values[i] + values[j] + i - j);
            }
        }
        return maxScore;
    }
    int optimised(vector<int>&values){
        int n = values.size();
        vector<int>prefix(n, 0);
        int result = 0;
        prefix[0] = values[0];
        for(int i = 1; i < values.size(); i++){
            prefix[i] = max(prefix[i - 1], values[i] + i);
        }
        for(int j = 1; j < n; j++){
            int jValue = values[j] - j;
            int iValue = prefix[j - 1];
            result = max(result, jValue + iValue);
        }
        return result;
    }
    int maxScoreSightseeingPair(vector<int>& values) {
        // return bruteForce(values);
        return optimised(values);
    }
};
