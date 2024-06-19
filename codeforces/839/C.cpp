#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

double get_expected_length(vector<vector<int>> &adj, int node, int parent){
    double sum = 0;
    int c = 0;
    for(auto &v: adj[node]){
        if(v == parent) continue;
        sum += get_expected_length(adj, v, node) + 1;
        c++;
    }
    return c == 0 ? 0 : sum / c;
}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n;
    cin >> n;

    vector<vector<int>> adj(n+1);

    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    double ans = get_expected_length(adj, 1, -1);

    cout << setprecision(7) << fixed << ans << "\n";

    return 0;
}