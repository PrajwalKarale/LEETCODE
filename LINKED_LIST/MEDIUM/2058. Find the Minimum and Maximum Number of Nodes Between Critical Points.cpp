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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        if(head==NULL || head->next==NULL ||head->next->next==NULL){
            return {-1,-1};
        }
        ListNode* prev = head;
        ListNode* current = head -> next;
        vector<int>criticalPos;
        int i = 1;
        while(current -> next != nullptr){
            if((current -> val > prev -> val && current -> val > current -> next -> val) || (current -> val < prev -> val && current -> val < current->next->val)){
                criticalPos.push_back(i+1);
            }
            i++;
            prev = current;
            current = current -> next;
        }
        if(criticalPos.size() < 2){
            return {-1,-1};
        }
        sort(criticalPos.begin(), criticalPos.end());
        vector<int>result;
        int minDistance = INT_MAX;
        for(int i = 1; i < criticalPos.size(); i++){
            int diff = criticalPos[i] - criticalPos[i - 1];
            minDistance = min(diff, minDistance);
        }
        result.push_back(minDistance);
        result.push_back(criticalPos[criticalPos.size() - 1] - criticalPos[0]);
        return result;
    }
};
