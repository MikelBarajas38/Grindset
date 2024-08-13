#include <bits/stdc++.h>
using namespace std;
    
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void dfs(int u, int p, vector<int> &depth, vector<vector<int>> &adj) {
    depth[u] = depth[p] + 1;
    for(int v : adj[u]) {
        if(v != p) {
            dfs(v, u, depth, adj);
        }
    }
}
    
void solve() {
    
    int n, q;
    cin >> n >> q;

    vector<vector<int>> adj(n + 1);
    vector<int> parent(n + 1);
    parent[1] = 1;

    for(int i = 2; i <= n; i++) {
        cin >> parent[i];
        adj[parent[i]].push_back(i);
    }

    vector<int> p(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    vector<int> depth(n + 1);
    dfs(1, 1, depth, adj);
    int max_depth = *max_element(all(depth));

    vector<int> permutation_depth(n + 1);
    for(int i = 1; i <= n; i++) {
        permutation_depth[p[i]] = depth[i];
    }

    while(q--) {

        int x, y;
        cin >> x >> y;

        swap(p[x], p[y]);
        swap(permutation_depth[p[x]], permutation_depth[p[y]]);

        bool ordered = true;

        vector<int> depth_checker(max_depth + 1, 0);
        for(int i = 1; i <= n; i++) {
            if(depth_checker[permutation_depth[i]] < 0) {
                ordered = false;
                break;
            }
            depth_checker[permutation_depth[i]] += 2;
            depth_checker[permutation_depth[i] - 1]--;
        }
        
        cout << (ordered ? "YES" : "NO") << '\n';

    }
    
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