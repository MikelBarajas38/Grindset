#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

    int max_val;

    int get_max_sum(TreeNode *node) {

        if(!node) {
            return 0;
        }

        int left_path = get_max_sum(node->left) + node->val;
        int right_path = get_max_sum(node->right) + node->val;

        max_val = max({left_path, right_path, left_path + right_path - node->val});

        return max(left_path, right_path);

    }

public:
    int maxPathSum(TreeNode* root) {

        max_val = root->val;
        
        get_max_sum(root);

        return max_val;
        
    }
};

int main() {

    Solution s;

    //[9,6,-3,null,null,-6,2,null,null,2,null,-6,-6,-6]

    TreeNode *root = new TreeNode(9);
    root->left = new TreeNode(6);
    root->right = new TreeNode(-3);
    root->right->left = new TreeNode(-6);
    root->right->right = new TreeNode(2);
    root->right->right->left = new TreeNode(2);
    root->right->right->right = new TreeNode(-6);
    root->right->right->right->left = new TreeNode(-6);
    root->right->right->right->right = new TreeNode(-6);

    cout << s.maxPathSum(root) << '\n';
    

}