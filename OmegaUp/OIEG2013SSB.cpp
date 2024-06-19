#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<vector<int>> adj;
vector<char> visited;

int main() {
	//cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);

    int N, E, T;
    cin >> N >> E >> T;

    vector<vector<int>> adj(N + 1);
    vector<char> visited(N + 1, 0);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    int marineros = 0;
    queue<int> q;

    q.push(N);
    visited[N] = 1;
    int count = q.size(), dist = 0;

    while (!q.empty() && dist < T) {
        int u = q.front();
        q.pop();
        marineros++;

        count--;

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = 1;
                q.push(v);
            }
        }

        if (count == 0) {
            count = q.size();
            dist++;
        }

    }

    if(marineros == 0) marineros = 1;
    cout << marineros - 1 << '\n';

    return 0;
}