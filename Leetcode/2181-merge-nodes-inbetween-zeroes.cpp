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
    int acum(ListNode* &curr) {
        if(curr->val == 0) {
            return 0;
        }
        int out = curr->val + acum(curr->next);
        curr = curr->next;
        return out;
    }

    ListNode* mergeNodes1(ListNode* head) {
        
        ListNode *curr = head;
        ListNode *prev = curr;
        while(curr->next) {
            curr->val = acum(curr->next);
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;

        return head;

    }

    ListNode* mergeNodes(ListNode* head) {
        
        ListNode* newHead = new ListNode(0);

        ListNode *curr = head -> next;
        ListNode *newCurr = newHead;
        int acum = 0;
        while(curr) {
            if(curr->val == 0) {
                newCurr->next = new ListNode(acum);
                newCurr = newCurr->next;
                acum = 0;
            } else {
                acum += curr->val;
            }
            curr = curr->next;
        }

        return newHead->next;

    }
};;