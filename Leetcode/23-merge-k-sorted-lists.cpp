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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<int> q;
        for(ListNode* current : lists) {
            while(current != nullptr) {
                q.push(- current -> val);
                current = current -> next;
            }
        }

        ListNode* superList = new ListNode();
        ListNode* current = superList;

        while (!q.empty()) {
            current->next = new ListNode(- q.top());
            q.pop();
            current = current->next;
        }

        return superList -> next;
    }
};