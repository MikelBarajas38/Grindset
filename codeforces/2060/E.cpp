#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int bad_edges = 0;
set<pair<int, int>> edges_to_delete;

void mark(int u, vector<set<int>> &G, vector<int> &visited, vector<int> &component, int comp) {
    visited[u] = 1;
    component[u] = comp;
    for(int v : G[u]) {
        if(!visited[v] && !edges_to_delete.count({u, v})) {
            mark(v, G, visited, component, comp);
        }
    }
}

vector<int> find_components(vector<set<int>> &G) {
    
    int n = G.size();
    vector<int> visited(n, 0);
    vector<int> component(n, -1);
    int comp = 0;

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            mark(i, G, visited, component, comp);
            comp++;
        }
    }

    return component;

}

void dfs(int u, vector<set<int>> &F, vector<int> &visited, vector<int> &c) {
    visited[u] = 1;
    for(int v : F[u]) {
        if(c[u] != c[v] && !edges_to_delete.count({u, v}) && !edges_to_delete.count({v, u})) {
            bad_edges++;
            edges_to_delete.insert({u, v});
            edges_to_delete.insert({v, u});
        }
        if(!visited[v]) {
            dfs(v, F, visited, c);
        }
    }
}

void solve() {

    bad_edges = 0;
    edges_to_delete.clear();
    
    int n, m1, m2;
    cin >> n >> m1 >> m2;

    vector<set<int>> F(n);
    vector<set<int>> G(n);

    for(int i = 0; i < m1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        F[u].insert(v);
        F[v].insert(u);
    }

    for(int i = 0; i < m2; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].insert(v);
        G[v].insert(u);
    }

    vector<int> G_components = find_components(G);

    vector<int> visited(n + 1, 0);
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i, F, visited, G_components);
        }
    }

    vector<int> F_components = find_components(F);

    bad_edges += (*max_element(all(F_components)) - *max_element(all(G_components)));

    cout << bad_edges << '\n';

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