#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

#define MOD (1000000007)
#define INF (MOD+1)

ll mod(ll a) {
    return ((a%MOD) + MOD) % MOD;
}

ll ext_euc(ll a, ll b, ll &x, ll &y) {
    ll xx = y = 0;
    ll yy = x = 1;
    while (b) {
        ll q = a/b;
        ll t = b;
        b = a%b;
        a = t;
        y = xx;
        xx = x-q*xx;
        x = t;
        t = yy;
        yy = y-q*yy;
        y = t;
    }
    return a;
}

ll modinv(ll a) {
    ll x, y;
    ll d = ext_euc(a, MOD, x, y);
    return mod(x);
}

int main() {

    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<ll, ll>>> adj(n);
    for(ll i = 0; i < m; ++i) {
        int a, b;
        ll d;
        cin >> a >> b >> d;
        adj[a].push_back({d, b});
        adj[b].push_back({d, b});
    }

    vll dist(n*1, INF);
    dist[0] = 0;
    priority_queue<pair<ll, ll>> pq;
    pq.push({0, 0});

    while(!pq.empty()) {

        auto [d, u] = pq.top();
        pq.pop();

        if(dist[u] < d) continue;

        for(auto &[d, v] : adj[u]) {
            if(dist[u] + d >= dist[v]) continue;
            dist[v] = dist[u] + d;
            pq.push({dist[v], v});
        }

    }

    sort(all(dist));

    ll prom = 0;

    for(int i = 1; i <= n-k; ++i) {
        prom = (prom % MOD + dist[i] % MOD) % MOD;
    }

    ll expected = ((prom % MOD) * modinv(n-k)) % MOD;

    cout << expected << '\n';
    
    return 0;
}
