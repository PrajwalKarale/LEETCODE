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
        1. We will be using the logic of Merge 2 sorted Linked List.
    Time Complexity:
        1. partitionAndMerge function takes log(k) time where k is the size of 'lists' and mergeTwoSortedLists takes O(n) where 
        n is the total number of nodes present in that specific linked list
        2. T.C -> O(log(k) * n)
    Space Complexity:
        1. S.C -> O(1) we have not used any auxiliary space only stack space is being used.
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    ListNode* mergeTwoSortedList(ListNode* l1, ListNode* l2){
        if(l1 == nullptr){
            return l2;
        }
        if(l2 == nullptr){
            return l1;
        }
        if(l1 -> val < l2 -> val){
            l1 -> next = mergeTwoSortedList(l1 -> next, l2);
            return l1;
        }else{
            l2 -> next = mergeTwoSortedList(l1, l2 -> next);
            return l2;
        }
    }
    ListNode* partitionAndMerge(int start, int end, vector<ListNode*>& lists){
        if(start == end){
            return lists[start];
        }
        int mid = start + (end - start) / 2;
        ListNode* l1 = partitionAndMerge(start, mid, lists);
        ListNode* l2 = partitionAndMerge(mid + 1, end, lists);
        return mergeTwoSortedList(l1, l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return nullptr;
        }
        return partitionAndMerge(0, lists.size() - 1, lists);
    }
};
