#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

    bool get_path(TreeNode *node, vector<int> &path, int goal) {
  
        if(!node) {
            return false;
        }
        
        if(node->val == goal) {
            path.push_back(node->val);
            return true;
        }
        
        if(get_path(node->left, path, goal)) {
            path.push_back(node->val);
            return true;
        }
        
        if(get_path(node->right, path, goal)) {
            path.push_back(node->val);
            return true;
        }
        
        return false;
    
    }

    void compare_paths(TreeNode *node, vector<int> current_path, vector<int> base_path, int k, vector<int> &result) {

        if(!node) {
            return;
        }

        current_path.push_back(node->val);

        compare_paths(node->left, current_path, base_path, k, result);
        compare_paths(node->right, current_path, base_path, k, result);

        reverse(current_path.begin(), current_path.end());

        // compare paths, and delete up to lca
        while(!current_path.empty() && !base_path.empty() && current_path.back() == base_path.back()) {
            current_path.pop_back();
            base_path.pop_back();
        }
    
        int distance = current_path.size() + base_path.size();
    
        //compare with k and store result
        if(distance == k) {
            result.push_back(node->val);
        }
    
    }

public:

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        vector<int> path_to_start;
        get_path(root, path_to_start, target->val);
        
        vector<int> result;
        compare_paths(root, {}, path_to_start, k, result);
    
        return result;
        
    }
};

int main() {

    Solution s;

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode *target = root->left;
    int k = 2;

    vector<int> result = s.distanceK(root, target, k);

    for(int &x : result) {
        cout << x << " ";
    }
    cout << '\n';

    return 0;
}