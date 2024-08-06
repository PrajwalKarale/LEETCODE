/*
T.C -> O(n*log(n))
S.C -> O(26) ~ constant space
*/
#include<execution>
class Solution {
public:
    int minimumPushes(string word) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int result = 0;
        vector<int>freq(26, 0);
        for(char &c: word){
            freq[c - 'a']++;
        }
        sort(execution::par_unseq, freq.begin(), freq.end(), greater{});
        for(int i = 0; i < 26; i++){
            int numberOfPress = i / 8 + 1;
            result = result + (numberOfPress * freq[i]);
        }
        return result;
    }
};
