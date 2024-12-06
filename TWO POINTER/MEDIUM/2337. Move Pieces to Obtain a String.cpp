/*
    Time Complexity:
        T.C -> O(n) where n is the length of the string
    Space Complexity:
        S.C -> O(1)
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    bool canChange(string start, string target) {
        // We will be following the two pointer approach
        int i = 0;
        int j = 0;
        int n = start.length();
        while(i < n || j < n){
            while(i < n && start[i] == '_'){
                i++;
            }
            while(j < n && target[j] == '_'){
                j++;
            }
            if(i == n || j == n){
                return i == n && j == n;
            }
            if(start[i] != target[j]){
                return false;
            }
            if(start[i] == 'L' && i < j){
                return false;
            }
            if(start[i] == 'R' && i > j){
                return false;
            }
            i++;
            j++;
        }
        return true;
    }
};
