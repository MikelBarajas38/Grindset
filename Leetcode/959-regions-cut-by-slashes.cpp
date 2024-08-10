#include <bits/stdc++.h>
using namespace std;

/*

" /" --> 000 001
         000 010
         000 100

"/ " --> 001 000
         010 000
         100 000

"/\" --> 001 100
         010 010
         100 001

"\/" --> 100 001
         010 010
         001 100

class Solution {

    bool valid(vector<string> &grid, int i, int j) {
        return(i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size());
    }

    void mark_region(vector<string> &grid, int i, int j) {

        vector<int> di = {0, 0, 1, -1};
        vector<int> dj = {1, -1, 0, 0};

        grid[i][j] = '1';

        for(int k = 0; k < 4; ++k) {
            int ni =  i + di[k];
            int nj =  j + dj[k];
            if(valid(grid, ni, nj) && grid[ni][nj] == '0') {
                mark_region(grid, ni, nj);
            }
        }

    }


public:

    int regionsBySlashes(vector<string>& grid) {
        
        unordered_map<char, string> top_part = {{' ', "000"},
                                                {'/', "001"},
                                                {'\\', "100"}};
        
        unordered_map<char, string> mid_part = {{' ', "000"},
                                                   {'/', "010"},
                                                   {'\\', "010"}};

        unordered_map<char, string> bottom_part = {{' ', "000"},
                                                   {'/', "100"},
                                                   {'\\', "001"}};

        vector<string> bin_grid;
        for(string &line : grid) {

            string top = "";
            string mid = "";
            string bottom = "";

            for(char &c : line) {
                top += top_part[c];
                mid += mid_part[c];
                bottom += bottom_part[c];
            }

            bin_grid.push_back(top);
            bin_grid.push_back(mid);
            bin_grid.push_back(bottom);
            
        }

        int n = grid.size();
        int regions = 0;
        for(int i = 0; i < 3 * n; ++i) {
            for(int j = 0; j < 3 * n; ++j) {
                if(bin_grid[i][j] == '0') {
                    regions++;
                    mark_region(bin_grid, i, j);
                }
            }
        }

        return regions;

    }
};

*/

/*

approach 2: turn each cell into two "triangle" nodes

each cell has two nodes: top and bottom

the nodes are connected as follows:

' ' --> adj[top] = {bottom, left_x, bottom_up}
       adj[bottom] = {top, right_x, bottom_down}

'/' --> adj[top] = {left_x, bottom_up}
        adj[bottom] = {right_X, bottom_down}

'\' --> adj[top] = {right, bottom_up}
        adj[bottom] = {left_x, bottom_down}

side nodes are chosen based on these rules:

if current cell is ' ':
    left = ' ' ? bottom -> left_top
    left = '/' ? bottom -> left_top
    left = '\' ? bottom -> left_bottom

if current cell is '/':
    left = ' ' ? bottom -> left_top
    left = '/' ? bottom -> left_top
    left = '\' ? bottom -> left_bottom

if current cell is '\':
    left = ' ' ? top -> left_top
    left = '/' ? top -> left_top
    left = '\' ? top -> left_bottom 

*/

class Solution {

    void mark(int u, vector<vector<int>> &adj, vector<bool> &used) {

        used[u] = true;

        for(int &v : adj[u]) {
            if(!used[v]) {
                mark(v, adj, used);
            }
        }

    }

public:

    int regionsBySlashes(vector<string>& grid) {
        
        int cells = grid.size();

        int n = cells * cells * 2;
        vector<vector<int>> adj(n + 1);

        // turn each cell into two nodes first:top, second:bottom
        vector<vector<pair<int, int>>> node_grid(cells, vector<pair<int,int>>(cells));
        for(int i = 0; i < cells; ++i) {
            for(int j = 0; j < cells; ++j) {
                int index = (i * cells * 2) + (j + 1) * 2;
                node_grid[i][j].first = index - 1;
                node_grid[i][j].second = index;
            }
        }

        // connect nodes
        for(int i = 0; i < cells; ++i) {
            for(int j = 0; j < cells; ++j) {

                int top = node_grid[i][j].first;
                int bottom = node_grid[i][j].second;

                if(grid[i][j] == ' ') {
                    adj[top].push_back(bottom);
                    adj[bottom].push_back(top);
                }

                if(j != cells - 1) {

                    int left = grid[i][j + 1] == '/' ? node_grid[i][j + 1].first: // LT 
                                                        node_grid[i][j + 1].second; // LB

                    if(grid[i][j] == '\\') {

                        adj[top].push_back(left);
                        adj[left].push_back(top);

                    } else {
                            
                        adj[bottom].push_back(left);
                        adj[left].push_back(bottom);

                    } 
                }

                if(i != cells - 1) {
                    int down_top = node_grid[i + 1][j].first;
                    adj[bottom].push_back(down_top);
                    adj[down_top].push_back(bottom);
                }

            }
        }

        int regions = 0;
        vector<bool> used(n + 1);
        for(int u = 1; u <= n; ++u) {
            if(!used[u]) {
                regions++;
                mark(u, adj, used);
            }
        }

        return regions;

    }
};

/*

// from the editorial: https://leetcode.com/problems/regions-cut-by-slashes/solution/

approach 3: use each corner as a node, and connect them based on the cell
            use disjoint set union to find cycles (connected components)

" /" --> 1 - 2 - 4
"/ "    |   | / |
        3 - 5 - 6
        | / |   |
        7 - 8 - 9 


how?

*/


int main() {
    Solution s;
    vector<string> grid = {"//","/ "};
    cout << s.regionsBySlashes(grid) << '\n';
    return 0;
}