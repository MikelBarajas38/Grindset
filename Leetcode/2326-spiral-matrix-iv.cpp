#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {

    bool valid(int i, int j, int m, int n) {
        return (i >= 0 && i < m && j >= 0 && j < n);
    }

public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        
        int i = 0, j = 0, offset = 0;
        vector<int> di = {0, 1, 0, -1};
        vector<int> dj = {1, 0, -1, 0};

        vector<vector<int>> matrix(m, vector<int>(n, -1));
        
        ListNode* node = head;

        while(node) {

            if(valid(i, j, m, n) && matrix[i][j] == -1) {
                matrix[i][j] = node->val;
                node = node->next;
            } else { 
                i -= di[offset];
                j -= dj[offset];
                offset = (offset + 1) % 4;
            }

            i += di[offset];
            j += dj[offset];

        }

        return matrix;

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

    int m = 3, n = 5;
    vector<int> v = {3,0,2,6,8,1,7,9,4,2,5,5,0};
    ListNode* head = vecToLinkedList(v);

    Solution s;
    vector<vector<int>> output = s.spiralMatrix(m, n, head);

    for(auto row : output) {
        for(auto cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

}