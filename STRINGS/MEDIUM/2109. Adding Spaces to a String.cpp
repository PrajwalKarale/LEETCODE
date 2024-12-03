/*
    T.C -> O(n + m) where n is size of string and m is size of spaces
    S.C -> O(1)
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.size();
        int spaceIndex = 0;
        string result = "";
        result.reserve(n + spaces.size());
        for(int i = 0; i < n; i++){
            if(spaceIndex < spaces.size() && i == spaces[spaceIndex]){
                result += " ";
                spaceIndex++;
            }
            result += s[i];
        }
        return result;
    }
};
