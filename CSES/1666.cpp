#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void dfs(int u, auto &adj, auto &color) {
    for(int &v : adj[u]) {
        if(color[v] == -1) {
            color[v] = color[u];
            dfs(v, adj, color);
        }
    }
}

void solve() {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> color(n, -1);
    int current_color = 0;

    for(int u = 0; u < n; ++u) {
        if(color[u] == -1) {
            color[u] = current_color;
            dfs(u, adj, color);
            current_color++;
        }
    }

    int roads_needed = current_color - 1;

    cout << roads_needed << '\n';

    set<int> visited;
    visited.insert(color[0]);
    int u = 0;

    while(roads_needed) {
        int v = (u+1)%n;
        if(color[u] != color[v] && !visited.count(color[v])) {
            cout << u+1 << ' ' << v+1 << '\n';
            roads_needed--;
            visited.insert(color[v]);
        }
        u++;
    }

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int T = 1;
    //cin >> T;

    while(T--) {
        solve();
    }

    return 0;
}