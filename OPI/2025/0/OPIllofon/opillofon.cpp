#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int max_edge;

bool dfs(int u, int goal, int past, vector<vector<pair<int, int>>> &adj) {

    if(u == goal) {
        return true;
    }

    for(auto &[v, w] : adj[u]) {

        if(v == past) continue;

        if(dfs(v, goal, u, adj)) {
            max_edge = max(max_edge, w);
            return true;
        }

    }

    return false;

}

int get_max_edge(int s, int e, vector<vector<pair<int, int>>> &adj) {
    max_edge = -1;
    dfs(s, e, s, adj);
    return max_edge;
}

void solve() {

    int n, q;
    cin >> n >> q;

    vector<vector<pair<int, int>>> adj(n);
    for(int i = 0; i < n - 1; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        a--; b--;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    while(q--) {

        int a, b;
        cin >> a >> b;
        a--; b--;

        cout << get_max_edge(a, b, adj) << '\n';

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