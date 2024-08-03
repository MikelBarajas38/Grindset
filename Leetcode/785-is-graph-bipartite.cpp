class Solution {

    // check if two-colorable
    bool bipartite(vector<vector<int>>& adj, vector<bool> &visited, vector<bool> &color, int root) {

        queue<int> q;

        q.push(root);
        visited[root] = true;
        color[root] = 0;

        while(!q.empty()) {

            int u = q.front();
            q.pop();

            for(int &v : adj[u]) {
                if(!visited[v]) {
                    visited[v] = true;
                    color[v] = !color[u];
                    q.push(v);
                } else if(color[v] != !color[u]) {
                    return false;
                }
            }

        }

        return true;

    }

public:
    bool isBipartite(vector<vector<int>>& graph) {

        bool is_bipartite = true;
        int n = graph.size();

        vector<bool> visited(n);
        vector<bool> color(n);

        for(int u = 0; u < n; ++u) {
            if(!visited[u]) {
                is_bipartite &= bipartite(graph, visited, color, u);
            }
        }
        
        return is_bipartite;

    }
};