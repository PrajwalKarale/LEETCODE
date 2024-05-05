/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node -> val = node -> next -> val;
        while(node -> next -> next != nullptr){
            node -> next -> val = node -> next -> next -> val;
            node = node -> next;
        }
        node -> next = nullptr;
    }
};
