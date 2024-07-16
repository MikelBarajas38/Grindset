#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

/*
Two color is not enough to solve this problem.
4
100 1 2 200
1 2
2 3
3 4
*/

void dfs(int u, vector<vector<int>>& adj, vector<char>& color, vector<char>& visited) {
    
    visited[u] = 1;
    
    for(int v : adj[u]) {
        if(!visited[v]) {
            color[v] = !color[u];
            dfs(v, adj, color, visited);
        }
    }
}

void solve() {

    ll n;
    cin >> n;

    vector<ll> damage(n + 1);
    ll total_damage = 0;
    for(int i = 1; i <= n; i++) {
        cin >> damage[i];
        total_damage += damage[i];
    }

    vector<vector<int>> adj(n + 1);

    set<int> right;
    for(int i = 1; i < n; i++) {
        int l, r;
        cin >> l >> r;
        adj[l].push_back(r);
        adj[r].push_back(l);
        right.insert(r);
    }

    int root = 0;
    for(int i = 1; i <= n; i++) {
        if(!right.count(i)) {
            root = i;
            break;
        }
    }

    vector<char> color(n + 1);
    vector<char> visited(n + 1);
    color[root] = 0;

    dfs(root, adj, color, visited);

    ll white_damage = 0, black_damage = 0;
    for(int i = 1; i <= n; i++) {
        if(color[i]) {
            black_damage += damage[i];
        } else {
            white_damage += damage[i];
        }
    }

 
    cout << total_damage + min(white_damage, black_damage) << '\n';

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