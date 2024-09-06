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
T.C -> O(n) where n = total number of eloements present in then linked list
*/
static const int speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>s(nums.begin(), nums.end());
        ListNode* dummy = new ListNode(-1);
        ListNode* temp1 = dummy;
        while(head != nullptr){
            if(s.find(head -> val) == s.end()){
                temp1 -> next = head;
                temp1 = temp1 -> next;
            }
            head = head -> next;
        }
        temp1 -> next = nullptr;
        return dummy -> next;
    }
};
