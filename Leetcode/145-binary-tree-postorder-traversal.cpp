/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

    void postorder(TreeNode *node, vector<int> &traversal) {

        if(!node) {
            return;
        }

        postorder(node->left,traversal);
        postorder(node->right,traversal);

        traversal.push_back(node->val);

    }

public:
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> traversal;
        postorder(root, traversal);
        return traversal;
        
    }
};