#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

auto initialize = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int memoize[101][101];
    int countSteps(int ringIndex, int indexAtWhichCharFound, int ringLength){
        int antiClockWise = abs(indexAtWhichCharFound - ringIndex);
        int clockWise = abs(ringLength - antiClockWise);
        return min(antiClockWise, clockWise);
    }
    int helper(int ringIndex, int keyIndex, string ring, string key){
        if(memoize[ringIndex][keyIndex] != -1){
            return memoize[ringIndex][keyIndex];
        }
        if(keyIndex >= key.length()){
            return 0;
        }
        int result = INT_MAX;
        for(int i = 0; i < ring.length(); i++){
            if(ring[i] == key[keyIndex]){
                int totalSteps = 1 + countSteps(ringIndex, i, ring.length())+ helper(i, keyIndex + 1, ring, key);
                result = min(result, totalSteps);
            }
        }
        return memoize[ringIndex][keyIndex] = result;
    }
    int findRotateSteps(string ring, string key) {
        memset(memoize, -1, sizeof(memoize));
        return helper(0, 0, ring, key);
    }
};
