class Solution {

    // floyd-warshall
    vector<vector<long long>> get_shortest_paths(vector<vector<long long>> &adj) {

        int n = adj.size(); //26
        vector<vector<long long>> P = adj;

        for(int k = 0; k < n; ++k) {
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {

                    if(P[i][k] != -1 && P[k][j] != -1) {
                        if(P[i][k] + P[k][j] < P[i][j] || P[i][j] == -1) {
                            P[i][j] = P[i][k] + P[k][j];
                        }
                    }

                }
            }
        }

        return P;

    }

public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {

        int V = original.size();
        vector<vector<long long>> adj(26, vector<long long>(26, -1));

        for(int i = 0; i < 26; ++i) {
            adj[i][i] = 0;
        }

        for(int i = 0; i < V; ++i) {

            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            long long w = (long long) cost[i];

            if(adj[u][v] == -1 || w < adj[u][v]) {
                adj[u][v] = w;
            }

        }

        vector<vector<long long>> total_cost = get_shortest_paths(adj);

        int len = source.size();
        long long min_cost = 0;

        for(int i = 0; i < len; ++i) {
            if(source[i] != target[i]) {

                int u = source[i] - 'a';
                int v = target[i] - 'a';

                if(total_cost[u][v] == -1) {
                    return -1;
                }

                min_cost += total_cost[u][v];

            }
        }

        return min_cost;
        
    }
};