#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct edge {
    int v;
    int x;
    int y;
};

void dfs(int u, vector<vector<edge>> &adj, vector<vector<int>> &adj2, vector<bool> &visited) {
    visited[u] = true;
    for(edge &e : adj[u]) {
        if(!visited[e.v]) {
            dfs(e.v, adj, adj2, visited);
        }
        if(e.x > e.y) {
            adj2[u].push_back(e.v);
        } else {
            adj2[e.v].push_back(u);
        }
    }

}

void dfs2(int u, vector<vector<int>> &adj2, vector<int> &p, vector<bool> &visited) {
    visited[u] = true;
    for(int &v : adj2[u]) {
        if(!visited[v]) {
            dfs2(v, adj2, p, visited);
        }
    }
    p.push_back(u + 1);
}

void solve() {

    int n;
    cin >> n;

    vector<vector<edge>> adj(n);
    for(int i = 0; i < n - 1; ++i) {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        adj[u-1].push_back({v-1, x, y});
    }

    vector<bool> visited(n);
    vector<vector<int>> adj2(n);
    for(int u = 0; u < n; ++u) {
        dfs(u, adj, adj2, visited);
    }

    vector<bool> visited2(n);
    vector<int> p;
    for(int u = 0; u < n; ++u) {
        if(!visited2[u]) {
            dfs2(u, adj2, p, visited2);
        }
    }

    vector<int> perm(n);
    for(int i = 0; i < n; ++i) {
        perm[p[i]-1] = i + 1;
    }

    for(int &x : perm) {
        cout << x << ' ';
    }
    cout << '\n';

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int T;
    cin >> T;

    while(T--) {
        solve();
    }

    return 0;
}