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
    ListNode* mergeKLists0(vector<ListNode*>& lists) {

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

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        int k = lists.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(int i = 0; i < k; ++i) {
            pq.push({lists[i]->val, i});
        }

        ListNode *super_root = new ListNode();
        ListNode *curr_node = super_root;

        while(!pq.empty()) {

            int current = pq.top().first;
            int i = pq.top().second;
            pq.pop();

            curr_node->next = new ListNode(current);
            curr_node = curr_node->next;

            lists[i] = lists[i]->next;
            if(lists[i]) {
                pq.push({lists[i]->val, i});
            }

        }

        return super_root->next;
        
    }
};