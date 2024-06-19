#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef vector<int> vi;

typedef struct {
    double l;
    double v;
} speed;

double inc = 0;
double INF = 10000000;
vector<vector<pair<int, speed>>> adj;

void dijkstra(int s, vector<double> & d) {
    int n = adj.size();
    d.assign(n, INF);

    d[s] = 0;
    using pii = pair<double, int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    
    q.push({0, s});

    while (!q.empty()) {

        int v = q.top().second;
        double d_v = q.top().first;
        q.pop();

        if (d_v != d[v])
            continue;

        for (auto edge : adj[v]) {
            int to = edge.first;
            double len = edge.second.l / (edge.second.v + inc);

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                q.push({d[to], to});
            }
        }
    }
}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n, m, t;
    cin >> n >> m >> t;

    adj.resize(n);
    for(int i=0; i<m; ++i) {
        int a, b;
        double l, v;
        cin >> a >> b >> l >> v;

        speed s = {l, v};

        adj[a-1].push_back({b-1, s});
        adj[b-1].push_back({a-1, s});
    }

    vector<double> d;
    dijkstra(0, d);
    double l = 0, r = 1e5;

    if (d[n-1] <= t) {
        cout << "0\n";
        return 0;
    }

    ll lim = 52500000;

    while(l < r && d[n-1] != t && lim--) {
        inc = (l + r) / 2;
        dijkstra(0, d);

        if(d[n-1] > t) {
            l = inc;
        } else {
            r = inc;
        }
    }

    cout << fixed << setprecision(7) << inc << '\n';

    return 0;
}