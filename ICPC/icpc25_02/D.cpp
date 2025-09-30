#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

class DSU {

    vector<int> parent;
    vector<int> size;

public:

    DSU(int n) : parent(n), size(n, 1) {
        iota(all(parent), 0);
    }

    int find(int u) {
        if(parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    int get_size(int u) {
        int pu = find(u);
        return size[pu];
    }

    void join(int u, int v) {

        int pu = find(u);
        int pv = find(v);

        if(pu == pv) {
            return;
        }

        if(size[pu] < size[pv]) {
            swap(pu, pv);
        }

        parent[pv] = pu;
        size[pu] += size[pv];
    }

};

void dfs_join(int u, vector<int> &energy, vector<vector<int>> &adj, DSU &dsu) {
    for(int &v : adj[u]) {
        if(energy[v] == energy[u] && dsu.find(u) != dsu.find(v)) {
            dsu.join(u, v);
            dfs_join(v, energy, adj, dsu);
        } else if(energy[v] < energy[u]) {
            dsu.join(u, v);
        }
    }
}

void solve() {

    int n, m;
    cin >> n >> m;

    vector<int> energy(n);
    vector<pair<int, int>> order;
    for(int i = 0; i < n; ++i) {
        cin >> energy[i];
        order.push_back({energy[i], i});
    }

    vector<vector<int>> adj(n);
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    sort(all(order));

    DSU dsu(n);
    vector<int> visitable(n);


    for(int i = 0; i < n; ++i) {

        int e = order[i].first;
        int u = order[i].second;

        //dfs_join(u, energy, adj, dsu);

        //visitable[u] = dsu.get_size(u);

        for(int v : adj[u]) {
            if(energy[u] >= energy[v]) {
                dsu.join(u, v);
            }
        }

        if(i == n-1 || e != order[i+1].first) {
            int j = i;
            while(j >= 0 && order[j].first == e) {
                visitable[order[j].second] = dsu.get_size(order[j].second);
                j--;
            }
        }

    }

    for(int &size : visitable) {
        cout << size << '\n';
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