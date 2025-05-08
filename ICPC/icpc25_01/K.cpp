#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define readv(_v) for (auto &_i : _v) cin >> i

void color_graph(int u, vector<vector<int>> &adj, vector<int> &color) {
    if(!adj[u].empty()) {
        for(int &v : adj[u]) {
            if(color[v] == -1) {
                color[v] = color[u];
                color_graph(v, adj, color);
            }
        }
    }
}

void dfs(int u, vector<vector<int>> &adj, vector<int> &topo, vector<bool> &visited) {
    if(!adj[u].empty()) {
        for(int &v : adj[u]) {
            if(!visited[v]) {
                visited[v] = true;
                dfs(v, adj, topo, visited);
            }
        }
    }
    topo.push_back(u);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, m;
    cin >> n >> m;

    vector<ll> cost(n);

    for(ll &c : cost) {
        cin >> c;
    }

    vector<vector<int>> adj(n);
    vector<vector<int>> adj_undirected(n);

    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj_undirected[a].push_back(b);
        adj_undirected[b].push_back(a);
    }

    vector<int> color(n, -1);
    int current_color = 0;

    for(int u = 0; u < n; ++u) {
        if(color[u] != -1) continue;
        color[u] = current_color;
        color_graph(u, adj_undirected, color);
        current_color++;
    }

    vector<bool> visited(n);
    vector<int> topo;

    for(int u = 0; u < n; ++u) {
        if(visited[u]) continue;
        dfs(u, adj, topo, visited);
    }

    reverse(begin(topo), end(topo));

    ll global_max = 0, local_max = 0, current_gold = 0;
    int past_color = color[topo[0]];

    for(int i = 0; i < n; ++i) {

        if(color[topo[i]] != past_color) {
            global_max += local_max;
            local_max = 0;
            current_gold = 0;
            past_color = color[topo[i]];
        }

        current_gold += cost[topo[i]];
        local_max = max(current_gold, local_max);

    }

    global_max += local_max;

    cout << global_max << '\n';


    return 0;
}