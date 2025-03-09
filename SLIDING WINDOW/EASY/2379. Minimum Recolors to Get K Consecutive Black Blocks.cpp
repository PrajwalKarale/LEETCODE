/*
    Logic:
        1. It is clear from the question that it can be solved using Sliding window.
    Time Complexity:
        1. T.C -> O(n) since we are traversing the whole string.
    Space Complexity:
        1. S.C -> O(1)
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length();
        int i = 0;
        int j = 0;
        int whiteBlocks = 0;
        int result = k;
        while(j < n){
            if(blocks[j] == 'W'){
                whiteBlocks++;
            }
            if(j - i + 1 == k ){
                result = min(result, whiteBlocks);
                if(blocks[i] == 'W'){
                    whiteBlocks--;
                }
                i++;
            }
            j++;
        }
        return result;
    }
};
