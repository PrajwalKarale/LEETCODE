/*
Logic:
-> i < j < k We are searching smaller elements than rating[j] in the left and greater elements than rating[j] in the right
-> i > j > k vice versa as we have done above.

1. T.C -> O(N^2) because the j loop will cover every element in the array which is taking O(N) time and within j loop the i loop and k loop are covering the elements of rating array once again
2. S.C -> O(1)
*/
class Solution {
public:
    int numTeams(vector<int>& rating) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int n = rating.size();
        int result = 0;
        for(int j = 0; j < n-1; j++){
            int smallerLeft = 0;
            int biggerRight = 0;
            int biggerLeft = 0;
            int smallerRight = 0;
            for(int i = 0; i < j; i++){
                if(rating[i] < rating[j]){
                    smallerLeft += 1;
                }
                if(rating[i] > rating[j]){
                    biggerLeft += 1;
                }
            }
            for(int k = j+1; k < n; k++){
                if(rating[k] > rating[j]){
                    biggerRight += 1;
                }
                if(rating[k] < rating[j]){
                    smallerRight += 1;
                }
            }
            result += (smallerLeft * biggerRight);
            result += (biggerLeft * smallerRight);
        }
        return result;
    }
};
