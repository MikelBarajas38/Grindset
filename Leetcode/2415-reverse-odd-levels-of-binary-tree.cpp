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

    void reverse_odd_levels1(TreeNode *left, TreeNode *right, bool parity) {
        
        if(!left || !right) {
            return;
        }

        if(parity) {
            swap(left->val, right->val);
        }

        reverse_odd_levels1(left->left, right->right, !parity);
        reverse_odd_levels1(left->right, right->left, !parity);

    }

public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        reverse_odd_levels(root, 0);
        return root;
    }
};