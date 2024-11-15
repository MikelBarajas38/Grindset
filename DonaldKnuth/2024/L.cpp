#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool bipartite;
bool first_time = true;

void dfs(vector<bool> &visited, vector<bool> &color, int u) {
    
    if(!bipartite) {
        return;
    }

    if(visited[u]) {
        return;
    }

    if(!first_time){
        cout << "M " << u << '\n';
        cout.flush();
    }
    first_time = false;

    visited[u] = true;

    int k;
    cin >> k;

    vector<int> neighbors(k);
    for(int &n : neighbors) {
        cin >> n;
    }

    for(int &v : neighbors) {

        if(!bipartite) {
            break;
        }

        if(!visited[v]) { 

            color[v] = !color[u];
            dfs(visited, color, v);

            if(bipartite) {
                cout << "M " << u << '\n';
                cout.flush();

                int k2;
                cin >> k2;

                vector<int> neighbors2(k2);
                for(int &n : neighbors2) {
                    cin >> n;
                }

            }

        } else if(color[v] == color[u]) {

            bipartite = false;
            break;

        }

    }

}

void solve() {
    
    vector<bool> visited(1001);
    vector<bool> color(1001);

    bipartite = true;
    
    dfs(visited, color, 1);

    if(bipartite) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    cout.flush();

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