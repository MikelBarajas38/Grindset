#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *next;
    Node *prev;
    Node(int x): val(x), next(nullptr) {}
};

class Solution {
public:

    int findTheWinner1(int n, int k) {
        
        vector<Node*> friends(n);
        for(int i = 0; i < n; i++) {
            friends[i] = new Node(i+1);
        }

        for(int i = 1; i < n; i++) {
            friends[i - 1]->next = friends[i];
            friends[i]->prev = friends[i-1];
        }
        friends[n-1]->next = friends[0];
        friends[0]->prev = friends[n-1];

        Node* node = friends[0];
        while(node->next != node) {

            for(int i = 1; i < k; i++) {
                node = node->next;
            }

            node->prev->next = node->next;
            node->next->prev = node->prev;

            node = node->next;

        }

        return node->val;

    }

    // n = number of friends, k = steps, steps are taken % m
    // m = n
    
    // friends - [1, 2, 3, 4, 5] m = 5
    //           [1, 3, 4, 5, X] m = 4
    //           [1, 3, 5, X, X] m = 3
    //           [3, 5, X, X, X] m = 2
    //           [3, X, X, X, X] m = 1

    // [1, 2, 3, 4, 5, 6]
    // [1, 2, 3, 4, 6, x]
    // [1, 2, 3, 6, x, x]
    // [1, 2, 3, x, x, x]
    // [1, 3, x, x, x, x]
    // [1, x, x, x, x, x]
    
    int findTheWinner2(int n, int k) {

        vector<int> friends(n);
        for(int i = 0; i < n; i++) {
            friends[i] = i + 1;
        }

        int p = 0, m = n;
        while(m > 1) {

            p = (p + k - 1) % m;

            for(int i = p; i < m - 1; i++) {
                friends[i] = friends[i+1];
            }

            m--;

        }

        return friends[0];

    }

    // josephus problem
    int findTheWinner(int n, int k) {

        int p = 0;
        for(int i = 2; i <= n; i++) {
            p = (p + k) % i;
        }
        return p + 1;
    }

};

int main() {

    Solution s;
    cout << s.findTheWinner(5, 2) << '\n';
    cout << s.findTheWinner(6, 5) << '\n';
    cout << s.findTheWinner(10, 17) << '\n';

    return 0;

}