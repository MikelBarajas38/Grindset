class Solution {
private:

    bool dfs(TreeNode node, int target, vector<int> &path){ // 0

        if(!node) { 
            return false;
        }

        if(node->val == target) { // 
            path.push_back(node->val);
            return true;
        }

        if(dfs(node->left, target, path)) { // 
            path.push_back(node->val);
            return true;
        }

        if(dfs(node->right, target, path)) { //
            path.push_back(node->val);
            return true;
        }

        return false;

    }

public:
    int findDistance(TreeNode root, int p, int q) { // p = 5, q = 0

        vector<int> path_from_root_to_p; // [5, 3]
        dfs(root, p, path_from_root_to_p); //

        vector<int> path_from_root_to_q; // [0, 1, 3]
        dfs(root, q, path_from_root_to_q); //

        // [5], [0, 1]
        while(path_from_root_to_p.size() > 0 && path_from_root_to_q.size() > 0 && path_from_root_to_p.back() == path_from_root_to_q.back()) {
            path_from_root_to_p.pop_back();
            path_from_root_to_q.pop_back();
        }

        // [5] = 1, [0, 1] = 2, 1 + 2 = 3
        return path_from_root_to_p.size() + path_from_root_to_q.size();

    }
};