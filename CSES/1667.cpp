#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<int> get_shortest_path(int a, int b, auto &adj) {

    int n = adj.size();

    vector<int> prev(n, -1);
    prev[a] = a;

    queue<int> q;
    q.push(a);

    bool finished = false;

    while(!q.empty()) {

        if(finished) {
            break;
        }

        int u = q.front();
        q.pop();

        for(int &v : adj[u]) {
            if(prev[v] == -1) {
                prev[v] = u;
                if(v == b) {
                    finished = true;
                }
                q.push(v);
            }
        }

    }

    if(!finished) {
        return {};
    }

    vector<int> path;
    while(b != a) {
        path.push_back(b);
        b = prev[b];
    }
    path.push_back(a);
    reverse(all(path));

    return path;

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

    vector<int> path = get_shortest_path(0, n-1, adj);

    if(path.empty()) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << path.size() << '\n';
        for(int &x : path) {
            cout << x+1 << ' ';
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