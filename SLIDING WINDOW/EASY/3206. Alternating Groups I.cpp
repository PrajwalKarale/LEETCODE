/*
 * @lc app=leetcode id=3206 lang=cpp
 *
 * [3206] Alternating Groups I
 */

/*
    Logic:
        1. Alterating group is a group which woulkd be of three length so our target is to find such groups and is should be alternating.
        2. It feels like it is a problem of fixed-length sliding window.
        3. It is being given that it is a circular array one thing we can do is extend the given array with the same array.
        4. One more way to handle the index are doing modulo n where n is the size of the vector. So if n is the length of the array and we are on n-1th index and then  we need to check on the first index 
        it will be (i + 1) % n where i = n-1th index. Other case will be that when index `i` will be 0 so when we have to see the previous index it will be -1
    Time Complexity:
        1. T.C -> O(n) where n is the total length of the array.
    Space Complexity;
        1. S.C -> O(1)
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
// @lc code=start
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size();
        int answers = 0;
        for(int i = 0; i < n; i++){
            if(colors[i] != colors[(i - 1 + n) % n] && colors[i] != colors[(i + 1) % n]){
                answers++;
            }
        }
        return answers;
    }
};
// @lc code=end

