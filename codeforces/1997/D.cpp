#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int dfs(vector<vector<int>>& adj, vector<int>& values, int u) {

    if(adj[u].empty()) {
        return values[u];
    }

    int min_child = 0;
    int min_child_value = INT_MAX;

    for(auto &v : adj[u]) {

        int min_subtree_value = dfs(adj, values, v);

        if(min_subtree_value < min_child_value) {
            min_child_value = min_subtree_value;
            min_child = v;
        }

    }

    if(u == 1) {
        return min_child_value;
    }

    if(values[u] < min_child_value) {
        int mid = (min_child_value - values[u]) / 2;
        values[u] += mid;
        values[min_child] -= mid;
    }

    values[u] = min(values[u], values[min_child]);

    return values[u];

}

void solve() {

    int n;
    cin >> n; 

    vector<int> values(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> values[i];
    }

    vector<vector<int>> adj(n + 1);
    for(int i = 2; i <= n; i++) {
        int parent;
        cin >> parent;
        adj[parent].push_back(i);
    }

    cout << values[1] + dfs(adj, values, 1) << '\n';

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