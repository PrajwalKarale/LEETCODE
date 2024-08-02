/*
1. Intuition: First we calculate the total number of 1s so that is the maximum number of swaps we will be requiring.
2. This problem qualifies in the sliding window category in which fixed size window is used.
3. Lets analyze the T.C:
   a. For calculating 'numberOfOnes' -> O(n)
   b. While loop will also run for O(n)
   c. T.C -> O(2n) ~ O(n)
4. Lets analyze the S.C
   a. S.C -> O(1) since no external memory is used
*/
class Solution {
public:
    int minSwaps(vector<int>& data) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int numberOfOnes = 0;
        for(int &ele: data){
            if(ele == 1){
                numberOfOnes++;
            }
        }
        if(numberOfOnes == 1 || numberOfOnes == data.size() - 1){
            return 0;
        }
        cout << numberOfOnes << data.size();
        int currentOnes = 0;
        for(int i = 0; i < numberOfOnes; i++){
            if(data[i] == 1){
                currentOnes++;
            }
        }
        int minimumSwaps = numberOfOnes - currentOnes;
        int left = 0;
        int right = numberOfOnes;
        while(right < data.size()){
            if(data[left] == 1){
                currentOnes--;
            }
            left++;
            if(data[right] == 1){
                currentOnes++;
            }
            right++;
            minimumSwaps = min(minimumSwaps, numberOfOnes - currentOnes);
        }
        return minimumSwaps;
    }
};
