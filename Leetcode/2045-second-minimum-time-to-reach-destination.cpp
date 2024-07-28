#include <bits/stdc++.h>
using namespace std;

/*

given example 2, there is always a second shortest path = shortest path + 2 (going back and forth)

1. find the shortest path from 1 to n
2 find if there is a path that is 1 more than the shortest path
3. if not, second shortest path is shortest path + 2

*/

class Solution {

    /*
    vector<int> get_min_dist(vector<vector<int>> adj, int start) {

        int n = adj.size() - 1;

        vector<int> dist(n);
        vector<bool> visited(n);

        queue<int> q;
        q.push(start);

        while(!q.empty()) {

            int u = q.front();
            q.pop();

            for(int v = 1; v <= n; v++) {
                if(adj[u][v] && !visited[v]) {
                    visited[v] = true;
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }

        }

        return dist;
        
    }

    void mmult(vector<vector<int>> &a, vector<vector<int>> &b) {

        int n = a.size();
        vector<vector<int>> res(n, vector<int>(n, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {
                    res[i][j] += a[i][k] * b[k][j];
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) { 
                a[i][j] = res[i][j];
            }
        }

    }

    // neat idea, crazy complexity
    int get_second_shortest_path1(vector<vector<int>> adj, int start, int end) {

        int n = adj.size();

        vector<int> shortest_path = get_min_dist(adj, start);

        int shortest = shortest_path[end];
        int exponent = shortest + 1; // test if there is a path that is 1 more than the shortest path

        vector<vector<int>> exp_adj(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) {
            exp_adj[i][i] = 1;
        }

        while(exponent) {
            if(exponent & 1) {
                mmult(exp_adj, adj);
            }
            mmult(adj, adj);
            exponent >>= 1;
        }

        if(exp_adj[start][end] != 0) {
            return shortest + 1;
        } 

        return shortest + 2;
        
    }

    
    bool path_of_size_k(vector<vector<int>> &adj, vector<bool> &visited, int u, int end, int k) {

        if(k == 0) {
            return u == end;
        }

        bool path_exists = false;

        for(int &v : adj[u]) {
            if(!path_exists && !visited[v]) {
                visited[v] = true;
                path_exists = path_exists || path_of_size_k(adj, visited, v, end, k - 1);
                visited[v] = false;
            }
        }

        return path_exists;

    }

    int get_second_shortest_path(vector<vector<int>> adj, int start, int end) {

        int n = adj.size() - 1;

        vector<int> dist = get_min_dist(adj, start);

        int shortest = dist[end];
        int second_shortest = shortest + 1; // test if there is a path that is 1 more than the shortest path
    
        // test if there is a path that is 1 more than the shortest path  

        return shortest + 2;

    }
    */

    int get_second_shortest_path(vector<vector<int>> adj, int start, int end) { 
    
        int n = adj.size() - 1;

        vector<int> dist(n+1, -1);
        vector<int> dist2(n+1, -1);

        queue<pair<int,int>> q;

        q.push({start, 1});
        dist[start] = 0;

        while(!q.empty()) {

            auto [u, visits] = q.front();
            q.pop();

            int curr_dist = visits == 1 ? dist[u] + 1 : dist2[u] + 1;

            for(int v : adj[u]) {

                if(dist[v] == -1) {
                    dist[v] = curr_dist;
                    q.push({v, 1});
                } else if(dist2[v] == -1 && dist[v] != curr_dist) {
                    dist2[v] = curr_dist;
                    q.push({v, 2});
                }

            }

        }

        return dist2[end];

    }

public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {

        vector<vector<int>> adj(n + 1);

        for(auto &edge : edges) {

            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

        }
        
        int second_shortest_path = get_second_shortest_path(adj, 1, n);
        int final_time = 0, current_time = 0;

        for(int i = 0; i < second_shortest_path; i++) {
            
            if((final_time / change) % 2) {
                final_time += (change - final_time % change);
            } 

            final_time += time;

        }

        return final_time;

    }
};

int main() {

    Solution s;

    int n = 5;
    vector<vector<int>> edges = {{1,2},{1,3},{1,4},{3,4},{4,5}};
    int time = 3;
    int change = 5;

    cout << s.secondMinimum(n, edges, time, change) << '\n';

    return 0;

}