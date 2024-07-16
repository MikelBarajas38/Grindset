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
    void dfs2(TreeNode *node, int start, int end, bool &start_found, bool &end_found, string &path) {

        if(!node) {
            return;
        }

        if(node->val == start) {
            start_found = true;
        } 

        if(start_found && node->val == end) {
            end_found = true;
        }

        if(!start_found) {
            dfs2(node->left, start, end, start_found, end_found, path);
            if(start_found && !end_found) {
                path += 'U';
            } else {
                dfs2(node->right, start, end, start_found, end_found, path);
                if(start_found && !end_found) {
                    path += 'U';
                }
            }
        }

        if(start_found && !end_found) {
            dfs2(node->left, start, end, start_found, end_found, path);
            if(end_found) {
                path += 'L';
            } else {
                dfs2(node->right, start, end, start_found, end_found, path);
                if(end_found) {
                    path += 'R';
                }
            }
        }

    }

    bool dfs(TreeNode *node, int goal, string &path) {

        if(!node) {
            return false;
        }

        if(node->val == goal) {
            return true;
        }

        if(dfs(node->left, goal, path)) {
            path += 'L';
            return true;
        }

        if(dfs(node->right, goal, path)) {
            path += 'R';
            return true;
        }

        return false;
    }

public:
    string getDirections2(TreeNode* root, int startValue, int destValue) { 
        bool start_found = false;
        bool end_found = false;
        string path = "";
        dfs2(root, startValue, destValue, start_found, end_found, path);

        auto it = path.begin();
        while(it != path.end() && *it == 'U') {
            it++;
        }
        reverse(it, path.end());

        return path;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        
        string path_to_start = "";
        dfs(root, startValue, path_to_start);
        reverse(path_to_start.begin(), path_to_start.end());

        string path_to_dest = "";
        dfs(root, destValue, path_to_dest);
        reverse(path_to_dest.begin(), path_to_dest.end());

        int i = 0;
        while(i < path_to_start.size() && i < path_to_dest.size() && path_to_start[i] == path_to_dest[i]) {
            i++;
        }

        path_to_start = string(path_to_start.size() - i, 'U');
        path_to_dest = path_to_dest.substr(i);

        return path_to_start + path_to_dest;
    }
};

int main() {

    Solution s;

    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(4);    

    cout << s.getDirections(root, 3, 6) << '\n';

    TreeNode *root2 = new TreeNode(2);
    root2->left = new TreeNode(1);

    cout << s.getDirections(root2, 2, 1) << '\n';

    TreeNode *root3 = new TreeNode(1);
    root3->right = new TreeNode(10);
    root3->right->left = new TreeNode(12);
    root3->right->right = new TreeNode(13);
    root3->right->left->right = new TreeNode(6);
    root3->right->left->left = new TreeNode(4);
    root3->right->right->right = new TreeNode(15);

    cout << s.getDirections(root3, 6, 15) << '\n';
}