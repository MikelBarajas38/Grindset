#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool dfs(int u, auto &adj, auto &color) {
    bool two_colorable = true;
    for(int &v : adj[u]) {
        if(color[v] == -1) {
            color[v] = 1 - color[u];
            two_colorable &= dfs(v, adj, color);
        } else {
            two_colorable &= color[v] != color[u];
        }
    }
    return two_colorable;
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
    bool two_colorable = true;

    for(int u = 0; u < n; ++u) {
        if(color[u] == -1) {
            color[u] = 0;
            two_colorable &= dfs(u, adj, color);
        }
    }

    if(!two_colorable) {
        cout << "IMPOSSIBLE\n";
    } else {
        for(int &c : color) {
            cout << c + 1 << ' ';
        }
        cout << '\n';
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