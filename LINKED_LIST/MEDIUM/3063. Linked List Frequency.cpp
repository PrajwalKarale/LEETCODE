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

static int fast_io = []() { std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();

class Solution {
public:
    __attribute__((disable_sanitizer_instrumentation))
    ListNode* frequenciesOfElements(ListNode* head) {
        map<int,int>freq;
        ListNode* current = head;
        while(current != nullptr){
            freq[current -> val] += 1;
            current = current -> next;
        }
        ListNode* tempNode = new ListNode();
        ListNode* tempCurrent = tempNode;
        for(const auto& [value, frequency] : freq){
            tempCurrent -> next = new ListNode(frequency);
            tempCurrent = tempCurrent -> next;
        }
        return tempNode -> next;
    }
};
