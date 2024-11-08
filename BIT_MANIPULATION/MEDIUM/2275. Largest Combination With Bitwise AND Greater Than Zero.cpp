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
