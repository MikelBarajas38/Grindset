#include <bits/stdc++.h>
using namespace std;

class Solution {

    // dijkstra
    vector<double> get_most_probable_paths(vector<vector<pair<int, double>>> &adj, int start) {

        int n = adj.size();

        vector<bool> visited(n);
        vector<double> prob(n);

        priority_queue<pair<double, int>> q;
        q.push({1, start});
        
        visited[start] = true;
        prob[start] = 1;

        while(!q.empty()) {

            int u = q.top().second;
            double p_u = q.top().first;
            q.pop();

            if(p_u != prob[u]) {
                continue;
            }

            for(auto &[v, p_v] : adj[u]){
                if(prob[u] * p_v > prob[v]) {
                    prob[v] = prob[u] * p_v;
                    q.push({prob[v], v});
                }
            }

        }

        return prob;

    }

public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {

        vector<vector<pair<int, double>>> adj(n);

        int V = edges.size();
        for(int i = 0; i < V; ++i) {

            int a = edges[i][0];
            int b = edges[i][1];

            adj[a].push_back({b, succProb[i]});
            adj[b].push_back({a, succProb[i]});

        }

        vector<double> paths = get_most_probable_paths(adj, start_node);
        return paths[end_node];        
        
    }
};

int main() {

    Solution s;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {0, 2}};
    vector<double> succProb = {0.5, 0.5, 0.2};
    cout << s.maxProbability(3, edges, succProb, 0, 2) << '\n';

    return 0;
}