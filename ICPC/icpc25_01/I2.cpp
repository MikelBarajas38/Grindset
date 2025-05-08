#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define readv(_v) for (auto &_i : _v) cin >> i

void dfs(int u, vector<vector<int>> &adj, vector<int> &topo, vector<int> &size) {
    if(!adj[u].empty()) {
        for(int &v : adj[u]) {
            dfs(v, adj, topo, size);
            size[u] += size[v];
        }
    }
    size[u]++;
    topo.push_back(u);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, q;
    cin >> n >> q;

    vector<int> skills(n);

    for(int &skill : skills) {
        cin >> skill;
    }

    vector<vector<int>> adj(n);
    for(int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
    }

    vector<int> topo;
    vector<int> size(n);

    dfs(0, adj, topo, size);

    reverse(begin(topo), end(topo));

    vector<unordered_map<int, int>> suc(n);

    for(int i = 0; i < n; ++i) {
        int u = topo[i];
        for(int j = i; j < i + size[u]; ++j) {
            int v = topo[j];
            suc[u][skills[v]]++;
        }
    }

    while(q--) {
        int u, s;
        cin >> u >> s;
        u--;
        cout << suc[u][s] << '\n';
    }

    return 0;
}