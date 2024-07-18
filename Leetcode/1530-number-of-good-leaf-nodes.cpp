#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    
    vector<int> dfs(TreeNode* node, int max_dist, int &pairs) {
        
        if (!node) {
            return {};
        }
        
        if (!node->left && !node->right) {
            return {0};
        }
        
        vector<int> left = dfs(node->left, max_dist, pairs);
        vector<int> right = dfs(node->right, max_dist, pairs);
        
        for (int l : left) {
            for (int r : right) {
                if (l + r + 2 <= max_dist) {
                    pairs++;
                }
            }
        }
        
        vector<int> result;

        for (int l : left) {
            if (l + 1 < max_dist) {
                result.push_back(l + 1);
            }
        }

        for (int r : right) {
            if (r + 1 < max_dist) {
                result.push_back(r + 1);
            }
        }
        
        return result;
    }
    
public:
    int countPairs(TreeNode* root, int distance) {
        int pairs = 0;
        dfs(root, distance, pairs);
        return pairs;
    }
};

int main() {

    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);

    cout << s.countPairs(root, 3) << '\n';

    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->left = new TreeNode(4);
    root2->left->right = new TreeNode(5);
    root2->right->left = new TreeNode(6);
    root2->right->right = new TreeNode(7);

    cout << s.countPairs(root2, 3) << '\n';


    return 0;

}