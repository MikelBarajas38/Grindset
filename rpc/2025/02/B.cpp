#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define MAX INT_MAX

enum Dir {
    UP=0,
    RIGHT=1,
    DOWN=2,
    LEFT=3
};

struct state {
    int i;
    int dir;
    int ki;
    int len;
    bool on;
    bool br;
};

pair<int,int> from_to(int curr, int next, vector<vector<int>> &adj) {
    for(int d = 0; d < 4; ++d) {
        if(adj[next][d] == curr) {
            return {d, (d + 2) % 4};
        }
    }
    return {-1, -1};
}

vector<int> get_possible_shortest_paths(int start, int end, int k, vector<vector<int>> &adj) {

    int n = adj.size();
    vector<int> dist(n, MAX);

    vector<vector<char>> visited(n, vector<char>(4));
    for(int i = 0; i < n; ++i) {
        for(int d = 0; d < 4; ++d) {
            visited[i][d] = adj[i][d] == -1;
        }
    }

    queue<state> q;
    dist[0] = 0;

    for(int d = 0; d < 4; ++d) {
        int neighbor = adj[0][d];
        if(neighbor != -1) {
            dist[neighbor] = 1;
            auto [in, out] = from_to(0, neighbor, adj);
            visited[neighbor][in] = false;
            q.push({adj[0][d], out, k, 1, false, false});
        }
    }

    while(!q.empty()) {

        auto [i, dir, ki, len, on, br] = q.front();
        q.pop();

        int up = adj[i][(dir+UP)%4];
        if(up != -1) {
            auto [in, out] = from_to(i, up, adj);
            if(!visited[up][in]) {
                dist[up] = min(len+1, dist[up]);
                visited[up][in] = true;
                q.push({up, out, ki, len+1, false, false});
            }
        }

        int right = adj[i][(dir+RIGHT)%4];
        if(right != -1) {
            auto [in, out] = from_to(i, right, adj);
            if(!visited[right][in]) {
                if((!on || !br) && ki) {
                    dist[right] = min(len+1, dist[right]);
                    visited[right][in] = true;
                    q.push({right, out, ki-1, len+1, true, true});
                } else if(on && br){
                    dist[right] = min(len+1, dist[right]);
                    visited[right][in] = true;
                    q.push({right, out, ki, len+1, true, true});
                }
            }
        }

        int left = adj[i][(dir+LEFT)%4];
        if(left != -1) {
            auto [in, out] = from_to(i, left, adj);
            if(!visited[left][in]) {
                if((!on || br) && ki) {
                    dist[left] = min(len+1, dist[left]);
                    visited[left][in] = true;
                    q.push({left, out, ki-1, len+1, true, false});
                } else if (on && !br){
                    dist[left] = min(len+1, dist[left]);
                    visited[left][in] = true;
                    q.push({left, out, ki, len+1, true, false});
                }
            }
        }

    }

    return dist;

}

void solve() {

    int n, k;
    cin >> n >> k;

    vector<vector<int>> adj(n, vector<int>(4));

    for(int i = 0; i < n; ++i) {
        for(int d = 0; d < 4; ++d) {
            cin >> adj[i][d];
            adj[i][d]--;
        }
    }

    int path_len = get_possible_shortest_paths(0, n-1, k, adj)[n-1];

    if(path_len == MAX) {
        cout << "impossible\n";
    } else {
        cout << path_len << '\n';
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