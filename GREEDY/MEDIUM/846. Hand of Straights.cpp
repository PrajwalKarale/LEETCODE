auto initialize = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0){
            return false;
        }
        if(groupSize == 1){
            return true;
        }
        sort(hand.begin(), hand.end());
        map<int,int>freq;
        for(int i = 0; i < hand.size(); i++){
            freq[hand[i]]++;
        }
        while(!freq.empty()){
            int currentEle = freq.begin() -> first;
            for(int i = 0; i < groupSize; i++){
                if(freq[currentEle + i] == 0){
                    return false;
                }
                freq[currentEle + i]--;
                if(freq[currentEle + i] < 1){
                    freq.erase(currentEle + i);
                }
            }
        }
        return true;
    }
};
