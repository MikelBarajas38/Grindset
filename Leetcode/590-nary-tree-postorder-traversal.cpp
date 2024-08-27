/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {

    void postorder(Node *node, vector<int> &traversal) {

        if(!node) {
            return;
        }

        for(Node* &c : node->children) {
            postorder(c, traversal);
        }

        traversal.push_back(node->val);

    }

public:
    vector<int> postorder(Node* root) {
        vector<int> traversal;
        postorder(root, traversal);
        return traversal;
    }
};