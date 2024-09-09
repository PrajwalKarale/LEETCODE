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
Time Complexity:
    1. O(K) for the outer for loop
    2. O(L) for finding the length of the linked list
    3. T.C = O(K + L)
Space Complexity:
    1. S.C = O(1)
*/
class Solution {
public:

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<ListNode*> result(k, nullptr);
        ListNode* current = head;
        int length = 0;
        while(current != nullptr){
            length += 1;
            current = current -> next;
        }
        int quotient = length / k;
        int extraNodes = length % k;
        ListNode* prev = nullptr;
        current = head;
        for(int i = 0; i < k; i++){
            result[i] = current;
            for(int count = 1; count <= quotient + (extraNodes > 0 ? 1 : 0); count++){
                prev = current;
                current = current -> next;
            }
            if(prev != nullptr){
                prev -> next = nullptr;
            }
            extraNodes--;
        }
        return result;
    }
};
