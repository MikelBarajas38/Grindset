#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<int> bfs(vector<vector<int>> &adj, int u) {

    queue<int> q;
    q.push(u);

    vector<int> dist(adj.size(), -1);
    dist[u] = 0;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int v : adj[u]) {
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    return dist;

}

void solve() {
    
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edges(m);
    for(int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second;
        edges[i].first--;
        edges[i].second--;
    }

    vector<int> ans(n, 1);
    for(int i = 0; i < m; i++) {

        if(edges[i].first > edges[i].second) {
            continue;
        }

        int diff = (edges[i].second - edges[i].first) / 2;
        for(int j = edges[i].second; j >= edges[i].second - diff; j--) {
            ans[j] = 0;
        }

    }

    for(int i = 0; i < n - 1; i++) {
        cout << ans[i];
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