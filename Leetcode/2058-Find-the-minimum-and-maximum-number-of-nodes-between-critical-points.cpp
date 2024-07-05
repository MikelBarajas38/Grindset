#include <bits/stdc++.h>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    bool isCriticalPoint(ListNode *prev) {

        if(!prev->next || !prev->next->next) {
            return false;
        }

        int prevVal = prev->val;
        int pointVal = prev->next->val;
        int nextVal = prev->next->next->val;

        // local maxima
        if(prevVal < pointVal && pointVal > nextVal) {
            return true;
        }

        //local minima
        if(prevVal > pointVal && pointVal < nextVal) {
            return true;
        }

        return false;

    }


    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        int minDistance = INT_MAX, maxDistance;
        ListNode* node = head;
        
        int firstCriticalPos = -1, lastCriticalPos = -1, currDistance = 0;

        while(node) {

            if(isCriticalPoint(node)) {
                if(firstCriticalPos == -1) {
                    firstCriticalPos = currDistance;
                    lastCriticalPos = currDistance;
                } else {
                    minDistance = min(minDistance, currDistance - lastCriticalPos);
                    lastCriticalPos = currDistance;
                }
            }

            currDistance++;
            node = node->next;

        }

        if(firstCriticalPos == lastCriticalPos) {
            return vector<int>({-1, -1});
        }

        maxDistance =  lastCriticalPos - firstCriticalPos;
        return vector<int>({minDistance, maxDistance});

    }
};

ListNode* vecToLinkedList(vector<int> &v) {

    ListNode* head = new ListNode();
    ListNode* curr = head;

    for(int i = 0; i < v.size(); i++) {
        curr->val = v[i];
        if(i < v.size() - 1) {
            curr->next = new ListNode();
            curr = curr->next;
        }
    }

    return head;

}

int main() {

    vector<int> v = {5,3,1,2,5,1,2};
    ListNode* head = vecToLinkedList(v); 

    Solution s;
    vector<int> result = s.nodesBetweenCriticalPoints(head);
    cout << "Min distance: " << result[0] << endl;
    cout << "Max distance: " << result[1] << endl;

    return 0;

}