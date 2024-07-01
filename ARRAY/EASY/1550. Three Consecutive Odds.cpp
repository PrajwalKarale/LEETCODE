class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        if(arr.size() < 3){
            return false;
        }
        for(int i = 0; i < arr.size() - 2; i++){
            int a = arr[i];
            int b = arr[i+1];
            int c = arr[i+2];
            if((a%2 == 1) && (b%2 == 1) && (c%2 == 1)){
                return true;
            }
        }
        return false;
    }
};
