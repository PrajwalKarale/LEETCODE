/*
    Logic:
        1. We need to return minimum number of boxes so that means we should start filling the apples in the box having the maximum capacity.
        2. Since it is being mentioned that apples from same pack can be distributed into different boxes
    Time Complexity:
        1. T.C -> O(n * log(n))
    Space Complexity:
        1. S.C -> O(1)
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
/*
    6
    5 4 3 2 1
*/
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalApples = 0;
        int result = 0;
        for(int &a: apple){
            totalApples += a;
        }
        sort(capacity.begin(), capacity.end(), greater<int>());
        for(int i = 0; i < capacity.size(); i++){
            if(totalApples <= 0){
                break;
            }
            totalApples -= capacity[i];
            result++;
        }
        return result;
    }
};
