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
const int ZERO = []()
{
std::ios_base::sync_with_stdio(false);
std::cin.tie(nullptr);
return 0;
}();

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
         if(head==NULL)return head;
        stack<ListNode*>st;
        ListNode* current = head;
        while(current != nullptr){
            while((!st.empty()) && (st.top() -> val < current -> val )){
                st.pop();
            }
            st.push(current);
            current = current -> next;
        }
        ListNode* nxt = nullptr;
        while(!st.empty()){
            current = st.top();
            st.pop();
            current -> next = nxt;
            nxt = current;
        }
        return current;
    }
};
