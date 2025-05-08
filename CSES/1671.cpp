#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<ll> get_shortest_paths(int start, auto &adj) {

    int n = adj.size();

    vector<ll> dist(n, LONG_MAX);
    dist[start] = 0;

    priority_queue<pair<ll,int>> pq;
    pq.push({0, start});

    while(!pq.empty()) {

        auto [d, u] = pq.top();
        pq.pop();

        d = -d;

        if(d > dist[u]) {
            continue;
        }

        for(auto &[v, w] : adj[u]) {
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({-dist[v], v});
            }
        }

    }

    return dist;

}

void solve() {

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, ll>>> adj(n);
    for(int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({v, w});
    }

    vector<ll> paths = get_shortest_paths(0, adj);

    for(ll &d : paths) {
        cout << d << ' ';
    }
    cout << '\n';

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