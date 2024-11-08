/*
    Time Complexity:
        1. T.C -> O(n) where n = candidates.size
        2. Since we will be traversing each and every element in the vector
    Space Complexity:
        1. S.C -> O(1)
*/
    Important
        1. Number of bits required to present a number m -> [floor($log{_2}{n}$)] +1

\(\log_2 m\)
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int n = candidates.size();
        int largestGroup = 0;
        for(int bitPos = 0; bitPos < 24; bitPos++){
            int count = 0;
            for(int &candidate: candidates){
                if((candidate & (1 << bitPos)) != 0){
                    count += 1;
                }
            }
            largestGroup = max(count, largestGroup);
        }
        return largestGroup;
    }
};
