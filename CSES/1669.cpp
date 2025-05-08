#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void dfs(int u, auto &adj, auto &path, auto &visited, bool &finished) {

    for(int &v : adj[u]) {
        if(!visited[v]) {

            visited[v] = true;
            path.push_back(v);
            dfs(v, adj, path, visited, finished);
            if(finished) {
                return;
            }
            path.pop_back();

        } else {

            int i = path.size() - 1;
            vector<int> cycle = {v};
            while(i >= 0 && path[i] != v) {
                cycle.push_back(path[i]);
                i--;
            }

            if(cycle.size() >= 3) {
                cycle.push_back(v);
                path = cycle;
                finished = true;
                return;
            }

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

    vector<int> path;
    vector<bool> visited(n);
    bool finished = false;

    for(int u = 0; u < n; ++u) {
        visited[u] = true;
        path.push_back(u);
        dfs(u, adj, path, visited, finished);
        if(finished) {
            break;
        }
        path.pop_back();
    }

    if(path.empty()) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << path.size() << '\n';
        for(int &u : path) {
            cout << u + 1 << ' ';
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