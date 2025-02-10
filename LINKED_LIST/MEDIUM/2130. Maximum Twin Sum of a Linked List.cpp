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
    Logic:
        1. Converting the given Linked List into vector and the applying two pointer approach.
        2. One small optimisation you can do is traverse only till half of the created vector
    Time Complexity:
        1. T.C -> O(n)
    Space Complexity:
        1. S.C -> O(n) since we have used vector as an auxiliary space.
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int>linkedList;
        ListNode* current = head;
        while(current != nullptr){
            linkedList.push_back(current -> val);
            current = current -> next;
        }
        int left = 0;
        int right = linkedList.size() - 1;
        int result = INT_MIN;
        while(left < right){
            int temp = linkedList[left] + linkedList[right];
            result = max(result, temp);
            left++;
            right--;
        }
        return result;
    }
};
