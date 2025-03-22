#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define INF DBL_MAX

struct edge {
    int node;
    double l;
    double v1;
    double v2;
};

double get_shortest_time(int start, int end, double delta_t, vector<vector<edge>> &adj) {

    int n = adj.size();

    vector<double> time(n, INF);
    time[start] = 0;

    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    pq.push({time[start], start});

    while(!pq.empty()) {

        auto [t, u] = pq.top();
        pq.pop();

        if(t > time[u]) {
            continue;
        }

        for(edge &e : adj[u]) {

            int v = e.node;

            double time_to_v;
            if(time[u] < delta_t) {
                double t1 = delta_t - time[u];
                double d1 = t1 * e.v1;
                if(d1 >= e.l) {
                    time_to_v = e.l / e.v1;
                } else {
                    double d2 = e.l - d1;
                    double t2 = d2 / e.v2;
                    time_to_v = t1 + t2;
                }
            } else {
                time_to_v = e.l / e.v2;
            }

            if(time[u] + time_to_v < time[v]) {
                time[v] = time[u] + time_to_v;
                pq.push({time[v], v});
            }

        }

    }

    return time[end];

}

void solve() {

    int n, m;
    double t;

    cin >> n >> m >> t;

    vector<vector<edge>> adj(n);
    for(int i = 0; i < m; ++i) {
        int x, y;
        double l, v, m;
        cin >> x >> y >> l >> v >> m;
        x--; y--;
        adj[x].push_back({y, l, v, m});
        adj[y].push_back({x, l, v, m});
    }

    double time = get_shortest_time(0, n-1, t, adj);

    cout << fixed << setprecision(6) << time << '\n';

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