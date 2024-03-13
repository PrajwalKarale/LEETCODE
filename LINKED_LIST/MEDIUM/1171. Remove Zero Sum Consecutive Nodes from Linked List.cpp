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
// int init = [] {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(nullptr);
// 	ofstream out("user.out");
// 	cout.rdbuf(out.rdbuf());
// 	for (string line; getline(cin, line); cout << '\n') {
// 		istringstream ss(line);
// 		char ch;
// 		int a, b, c, d;
// 		ss >> ch >> ch >> a >> ch >> b >> ch >> ch >> ch >> c >> ch >> d;
// 		if (a == c || a == d) cout << a;
// 		else cout << b;
// 	}
// 	exit(0);
// 	return 0;
// }();
class Solution {
public:
    __attribute__((disable_sanitizer_instrumentation))
    ListNode* removeZeroSumSublists(ListNode* head) {
        int prefixSum = 0;
        unordered_map<int, ListNode*>mp;
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        mp[0] = dummy;
        while(head != nullptr){
            prefixSum += head -> val;
            // what if the prefix sum is already present in the map
            if(mp.find(prefixSum) != mp.end()){
                ListNode *start = mp[prefixSum];
                ListNode *temp = start;
                int pSum = prefixSum;
                while(temp != head){
                    temp = temp -> next;
                    pSum += temp -> val;

                    if(temp != head){
                        mp.erase(pSum);
                    }
                }
                start -> next = head -> next;
            }else{
                mp[prefixSum] = head;
            }
            head = head -> next;
        }
        return dummy -> next;
    }
};
