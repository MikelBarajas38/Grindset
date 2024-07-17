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
private:

    void dfs(TreeNode ** node, unordered_set<int> &deleted, vector<TreeNode*> &roots) {
        if(!*node) {
            return;
        }

        dfs(&((*node)->left), deleted, roots);
        dfs(&((*node)->right), deleted, roots);

        if(deleted.count((*node)->val)) {
            if((*node)->left) roots.push_back((*node)->left);
            if((*node)->right) roots.push_back((*node)->right);
            delete *node; 
            *node = nullptr;
        }
    }

public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        unordered_set<int> deleted(to_delete.begin(), to_delete.end());

        vector<TreeNode *> roots;
        if(!deleted.count(root->val)) {
            roots.push_back(root);
        }


        dfs(&root, deleted, roots);

        return roots;

    }
};