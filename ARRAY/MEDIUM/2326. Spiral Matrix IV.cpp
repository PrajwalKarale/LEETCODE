/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/*
Time Complexity
    1. O(m * n) Since we are visiting each and every cell
Space Complexity
    1. O(1) since no extra space is being used
*/
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<vector<int>>result(m, vector<int>(n, -1));
        int id = 0;
        int top = 0;
        int down = m - 1;
        int left = 0;
        int right = n - 1;
        while(top <= down && left <= right){
            if(id == 0){
                //left to right
                for(int i = left; head != nullptr && i <= right; i++){
                    result[top][i] = head -> val;
                    head = head -> next;
                }
                top += 1;
            }
            if(id == 1){
                //top to down i.e row changes
                for(int i = top; head != nullptr && i <= down; i++){
                    result[i][right] = head -> val;
                    head = head -> next;
                }
                right -= 1;
            }
            if(id == 2){
                // right to left i.e column changes
                for(int i = right; head != nullptr && i >= left; i--){
                    result[down][i] = head -> val;
                    head = head -> next;
                }
                down -= 1;
            }
            if(id == 3){
                // from down to up i.e row changes
                for(int i = down; head != nullptr && i >= top ; i--){
                    result[i][left] = head -> val;
                    head = head -> next;
                }
                left++;
            }
            id = (id + 1) % 4;
        }
        return result;
    }
};
