/*
    Time Complexity:
        1. We are traversing each and every character in the string.
        2. T.C -> O(n) n = len(s)
    Space Complexity:
        1. S.C -> O(n) since we created a new string
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();
        string result = "";
        char prev = s[0];
        int frequency = 1;
        result.push_back(s[0]);
        for(int i = 1; i < n; i++){
            char currentChar = s[i];
            if(currentChar == prev){
                frequency+=1;
            }else{
                prev = currentChar;
                frequency = 1;
            }
            if(frequency < 3){
                result.push_back(currentChar);
            }
        }
        return result;
    }
};
