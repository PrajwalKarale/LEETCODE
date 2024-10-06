/*
    Time Complexity:
        1. O(s2_length) which is the length of the second string
    Space Complexity:
        1. S.C -> O(1) since no extra space is used.
*/

auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
};
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1Len = s1.length();
        int s2Len = s2.length();
        
        if(s1Len > s2Len){
            return false;
        }

        vector<int>s1Freq(26, 0);
        vector<int>s2Freq(26, 0);

        for(int i = 0; i < s1Len; i++){
            s1Freq[s1[i] - 'a']++;
        }
        int i = 0;
        int j = 0;
        while(j < s2Len){
            s2Freq[s2[j] - 'a']++;
            // Slinding window size is increased
            // so we need to shrink the window
            if(j - i + 1 > s1Len){
                s2Freq[s2[i] - 'a']--;
                i++;
            }
            if(s1Freq == s2Freq){
                return true;
            }
            j++;
        }
        return false;
    }
};
// @lc code=end
