#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define INF 10000000

void add_path(vector<vector<char>> &bp, vector<vector<int>> &P, int i, int j) {
    if(P[i][j] == 0) {
        bp[i][j] = true;
        bp[j][i] = true;
        return;
    }

    add_path(bp, P, i, P[i][j]);
    add_path(bp, P, P[i][j], j);
}

int floyd(vector<vector<int>> &m, int a, int b) {
    
    int n = m.size();
    
    vector<vector<int>> F(n, vector<int>(n));
    vector<vector<int>> P(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            F[i][j] = m[i][j];
        }   
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (F[i][j] > F[i][k] + F[k][j]) {
                    F[i][j] = F[i][k] + F[k][j];
                    P[i][j] = k; 
                }
            }
            
        }
        
    }

    set<pair<int,int>> best_paths;
    vector<vector<char>> used(n, vector<char>(n, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(F[a][b] == F[a][i] + F[i][j] + F[j][b]) {
                add_path(used, P, a, i);
                add_path(used, P, i, j);
                add_path(used, P, j, b);
            }
        }   
    }

    int c = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(!used[i][j] && m[i][j] < INF) {
                c += m[i][j];
                used[i][j] = true;
                used[j][i] = true;
            }
        }   
    }

    return c;
    
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n, m, a, b;
    cin >> n >> m >> a >> b;

    vector<vector<int>> adj(n, vector<int>(n, INF));

    int total = 0;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u-1][v-1] = w;
        adj[v-1][u-1] = w;
        total += w;
    }

    for(int i = 0; i < n; ++i) {
        adj[i][i] = 0;
    }

    cout << floyd(adj, a-1, b-1) << "\n";

    return 0;
}