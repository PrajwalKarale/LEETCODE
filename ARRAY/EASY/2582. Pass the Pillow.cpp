class Solution {
public:
    int passThePillow(int n, int time) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int direction = 1;
        int currPosition = 0;
        for(int i = 0; i < time; i++){
            //1->2->3->4
            if(direction == 1){
                if(currPosition == n - 1){
                    direction = -1;
                }
                currPosition += direction;
            }else{
                if(currPosition == 0){
                    direction = 1;
                }
                currPosition += direction;
            }
        }
        return currPosition + 1;
    }
};
