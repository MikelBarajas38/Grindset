#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void topo_dfs(auto &adj, auto &topo, int u) {
    for(const int &v : adj[u]) {
        topo_dfs(adj, topo, v);
    }
    topo.push_back(u);
}

void solve() {

    int n, m;
    cin >> n >> m;

    vector<set<int>> adj(n);
    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].insert(b);
    }

    vector<int> topo;
    topo_dfs(adj, topo, 0);
    reverse(all(topo));

    vector<vector<int>> paths(1);
    paths[0].push_back(topo[0]);

    for(int i = 1; i < n; ++i) {
        if(!adj[topo[i-1]].count(topo[i])) {
            paths.push_back({});
        }
        paths.back().push_back(topo[i]);
    }

    if(paths.size() == 2) {
        cout << "YES\n";
        for(auto &path : paths) {
            cout << path.size() << ' ';
            for(int &x : path) {
                cout << x << ' ';
            }
        }
    } else {
        cout << "NO\n";
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