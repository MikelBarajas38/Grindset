#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int t;

typedef struct {
    double km;
    double h;
    double d;
} speed;

const ll INF = 1000000000;
vector<vector<pair<int, speed>>> adj;

double fdxi(double x, speed &s) {
    return -s.km / (s.h+x)*(s.h+x);
}

double fdx(double x, vector<speed> &p) {
    double y = 0;

    for (speed s : p) {
        y += fdxi(x, s);
    }

    return y + t;
}

double fi(double x, speed &s) {
    return s.km / (s.h + x);
}

double f(double x, vector<speed> &p) {
    double y = 0;

    for (speed s : p) {
        y += fi(x, s);
    }

    return y - t;
}

void dijkstra(int s, vector<double> & d, vector<int> & p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);
    vector<bool> u(n, false);

    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!u[j] && (v == -1 || d[j] < d[v]))
                v = j;
        }

        if (d[v] == INF)
            break;

        u[v] = true;
        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second.d;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
}

vector<int> restore_path(int s, int t, vector<int> const& p) {
    vector<int> path;

    for (int v = t; v != s; v = p[v])
        path.push_back(v);
    path.push_back(s);

    reverse(path.begin(), path.end());
    return path;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n, m;
    cin >> n >> m >> t;
    map<pii, speed> match;

    adj.resize(n);
    for(int i=0; i<m; ++i) {
        int a, b;
        double l, v;
        cin >> a >> b >> l >> v;

        speed s = {l, v, l/v};

        if(match.count({a-1,b-1}) && match[{a-1,b-1}].d <= s.d) {
            continue;
        }

        adj[a-1].push_back({b-1, s});
        adj[b-1].push_back({a-1, s});
        match[{a-1, b-1}] = s;
        match[{b-1, a-1}] = s;
    }

    vector<double> d;
    vector<int> p;

    dijkstra(0, d, p);

    if(d[n-1] <= t) {
        cout << "0\n";
        return 0;
    }

    vi path = restore_path(0, n-1, p);
    vector<speed> path_info;
    for(int i=0; i<path.size()-1; ++i) {
        path_info.push_back(match[{path[i], path[i+1]}]);
    }

    // newton
    double x = 0;
    double y = f(x,path_info);

    while (y > 0.00000000009) {
        x = x - f(x,path_info)/fdx(x,path_info);
        y = f(x, path_info);
    }

    cout << fixed << setprecision(7) << x << '\n';

    return 0;
}