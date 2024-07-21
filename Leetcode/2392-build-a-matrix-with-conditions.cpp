#include<bits/stdc++.h>
using namespace std;

/*

idea: use toposort

rowConditions = [[1,2],[3,2]]

 1   3
  \ /
   2

topo_row = 1 3 2

colConditions = [[2,1],[3,2]]

3 - 2 - 1

topo_col = 3 2 1

then just fill when topo_row[i] == topo_col[j],
since we are building a k x k matrix with only k elements

*/

class Solution {

private:

    // return false if there is a cycle
    bool build_topo(int u, vector<vector<int>> &adj, vector<int> &topo, vector<bool> &visited, vector<bool> &in_path) {

        visited[u] = true; 
        in_path[u] = true;

        for(int &v : adj[u]) {
            if(!visited[v] && build_topo(v, adj, topo, visited, in_path)) {
                continue;
            } else if(in_path[v]) {
                return false;                
            }
        }

        topo.push_back(u);
        in_path[u] = false;

        return true;
    }

    vector<int> get_topo(vector<vector<int>> &conditions, int k) {

        vector<vector<int>> adj(k + 1);

        for(auto &t : conditions) {
            int a = t[0];
            int b = t[1];
            adj[a].push_back(b);
        }

        vector<int> topo;
        vector<bool> visited(k + 1);
        vector<bool> in_path(k + 1);

        for(int u = 1; u <= k; ++u) {
            if(!visited[u]) {
                if(!build_topo(u, adj, topo, visited, in_path)) {
                    return {};
                }
            }
        }

        reverse(topo.begin(), topo.end());

        return topo;

    }

public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        
        vector<int> row_topographic_restrictions = get_topo(rowConditions, k);

        if(row_topographic_restrictions.empty()) {
            return {};
        }

        vector<int> col_topographic_restrictions = get_topo(colConditions, k);

        if(col_topographic_restrictions.empty()) {
            return {};
        }

        vector<vector<int>> matrix(k, vector<int>(k, 0));

        for(int i = 0; i < k; ++i) {
            for(int j = 0; j < k; ++j) {
                if(row_topographic_restrictions[i] == col_topographic_restrictions[j]) {
                    matrix[i][j] = row_topographic_restrictions[i];
                }
            }
        }

        return matrix;

    }
};

int main() {

    Solution s;

    vector<vector<int>> rowConditions = {{1,2},{3,2}};
    vector<vector<int>> colConditions = {{2,1},{3,2}};

    vector<vector<int>> matrix = s.buildMatrix(3, rowConditions, colConditions);

    for(auto &row : matrix) {
        for(int &x : row) {
            cout << x << " ";
        }
        cout << '\n';
    }

    vector<vector<int>> rowConditions2 = {{1,2},{2,3},{3,1},{2,3}};
    vector<vector<int>> colConditions2 = {{2,1}};

    vector<vector<int>> matrix2 = s.buildMatrix(3, rowConditions2, colConditions2);

    for(auto &row : matrix2) {
        for(int &x : row) {
            cout << x << " ";
        }
        cout << '\n';
    }

    return 0;

}