#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct edge {
    ll u, v, w;
};


const ll MAX = 1e18;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    ll n, m;
    cin >> n >> m;

    vector<edge> edges;
    for(ll i = 0; i < m; ++i) {
        ll s, e, a;
        char t;
        cin >> s >> e >> t >> a;
        if(t == 'b') {
            edges.push_back({s, e, a});
        } else {
            edges.push_back({s, e, -a});
        }
    }

    vector<ll> dist(n + 1, MAX);
    dist[1] = 0;

    for(ll i = 0; i < n - 1; ++i) {
        for(auto &e : edges) {
            if(dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }

    for(int i = 0; i <= n; ++i) {
        if(dist[i] < 0) {
            cout << i << "\n";
        }
    }

    return 0;
}