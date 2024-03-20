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
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        ListNode* temp1 = list1;
        ListNode* temp2 = list1;
        //moving till a - 1 node.
        for(int i = 0; i < a - 1; i++){
            temp1 = temp1 -> next;
        }
        //moving till b+1 node
        for(int i = 0; i <= b; i++){
            temp2 = temp2 -> next;
        }
        //assigning temp1 to list2;
        temp1 -> next  = list2;
        //traversing list2 till the end.
        while(temp1 -> next != NULL){
            temp1 = temp1 -> next;
        }
        //assigning end of list2 to the remaining part of list1
        temp1 -> next = temp2;
        return list1;
        
    }
};
