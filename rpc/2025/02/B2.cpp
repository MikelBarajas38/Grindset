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
    int on;
    int br;
    int len;
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

    vector<vector<vector<vector<vector<char>>>>> visited(n,
        vector<vector<vector<vector<char>>>>(4,
            vector<vector<vector<char>>>(k+1,
                vector<vector<char>>(2,
                    vector<char>(2,
                        false
                    )
                )
            )
        )
    );

    queue<state> q;
    dist[start] = 0;

    for(int d = 0; d < 4; ++d) {
        int neighbor = adj[start][d];
        if(neighbor != -1) {
            auto [in, out] = from_to(start, neighbor, adj);
            visited[neighbor][out][k][0][0] = true;
            dist[neighbor] = 1;
            q.push({neighbor, out, k, 0, 0, 1});
        }
    }

    while(!q.empty()) {

        auto [i, dir, ki, on, br, len] = q.front();
        q.pop();

        int up = adj[i][(dir+UP)%4];
        if(up != -1) {
            auto [in, out] = from_to(i, up, adj);
            if(!visited[up][out][ki][0][0]) {
                dist[up] = min(len+1, dist[up]);
                visited[up][out][ki][0][0] = true;
                q.push({up, out, ki, 0, 0, len+1});
            }
        }

        int right = adj[i][(dir+RIGHT)%4];
        if(right != -1) {
            auto [in, out] = from_to(i, right, adj);
            if(ki && !visited[right][out][ki-1][1][1] && (!on || !br)) {
                dist[right] = min(len+1, dist[right]);
                visited[right][out][ki-1][1][1] = true;
                q.push({right, out, ki-1, 1, 1, len+1});
            } else if(!visited[right][out][ki][1][1] && (on && br)){
                dist[right] = min(len+1, dist[right]);
                visited[right][out][ki][1][1] = true;
                q.push({right, out, ki, 1, 1, len+1});
            }
        }

        int left = adj[i][(dir+LEFT)%4];
        if(left != -1) {
            auto [in, out] = from_to(i, left, adj);
            if(ki && !visited[left][out][ki-1][1][0] && (!on || br)) {
                dist[left] = min(len+1, dist[left]);
                visited[left][out][ki-1][1][0] = true;
                q.push({left, out, ki-1, 1, 0, len+1});
            } else if (!visited[left][out][ki][1][0] && (on && !br)){
                dist[left] = min(len+1, dist[left]);
                visited[left][out][ki][1][0] = true;
                q.push({left, out, ki, 1, 0, len+1});
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