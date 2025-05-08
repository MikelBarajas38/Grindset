#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define readv(_v) for (auto &_i : _v) cin >> i

void dfs(int u, vector<vector<int>> &adj, vector<map<int, int>> &suc) {

    if(adj[u].empty()) {
        return;
    }

    for(int &v : adj[u]) {

        dfs(v, adj, suc);
        
        auto a = suc[u];
        auto b = suc[v];

        if(a.size() < b.size()) {
            swap(a, b);
        }

        for(auto &[k, v] : b) {
            a[k] += v;
        }
        
        suc[u] = a;
        
    }

}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, q;
    cin >> n >> q;

    vector<int> skills(n);
    vector<map<int, int>> suc(n);

    for(int &skill : skills) {
        cin >> skill;
    }

    vector<vector<int>> adj(n);
    for(int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
    }

    for(int i = 0; i < n; ++i) {
        suc[i][skills[i]] = 1;
    }

    dfs(0, adj, suc);

    while(q--) {

        int u;
        ll s;
        cin >> u >> s;
        u--;

        if(!suc[u].count(s)) {
            cout << 0 << '\n';
            continue;
        }

        cout << suc[u][s] << '\n';

    }

    return 0;
}
