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

void printTree(TreeNode *root) {
    if(root == nullptr) {
        return;
    }

    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {

        unordered_map<int, TreeNode *> nodes;
        unordered_set<int> children;
        TreeNode *root = nullptr;

        for(auto &description : descriptions) {

            int parent = description[0];
            int child = description[1];
            int isLeft = description[2];

            if(nodes.count(child) == 0) {
                nodes[child] = new TreeNode(child);
            } 

            if(nodes.count(parent) == 0) {
                nodes[parent] = new TreeNode(parent);
            }

            if(isLeft) {
                nodes[parent]->left = nodes[child];
            } else {
                nodes[parent]->right = nodes[child];
            }

            children.insert(child);

        }

        for(auto &[id, node] : nodes) {
            if(children.count(id) == 0) {
                root = nodes[id];
                break;
            }
        }

        return root;
        
    }
};

int main() {

    Solution s;
    vector<vector<int>> descriptions = {{39,70,1},{13,39,1},{85,74,1},{74,13,1},{38,82,1},{82,85,1}};
    TreeNode *root = s.createBinaryTree(descriptions);
    printTree(root);
    cout << '\n';

    return 0;
}