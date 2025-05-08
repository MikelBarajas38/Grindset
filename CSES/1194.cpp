#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool bfs(int si, int sj, vector<string> &map, string &path) {

    int n = map.size();
    int m = map[0].size();

    queue<pair<int, int>> q;

    vector<int> di = {-1, 0, 1, 0};
    vector<int> dj = {0, 1, 0, -1};
    vector<char> dir = {'U', 'R', 'D', 'L'};

    vector<vector<int>> prev(n, vector<int>(m));

    q.push({si, sj});
    map[si][sj] = 'A';

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(map[i][j] == 'M') {
                q.push({i, j});
            }
        }
    }

    auto is_valid = [&](int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m;
    };

    int fi = -1, fj = -1;
    bool finished = false;

    while(!q.empty()) {

        if(finished) {
            break;
        }

        auto [i, j] = q.front();
        q.pop();

        for(int k = 0; k < 4; ++k) {
            int ni = i + di[k];
            int nj = j + dj[k];
            if(is_valid(ni, nj) && map[ni][nj] != '#') {
                if(map[i][j] == 'A' && map[ni][nj] == '.') {
                    prev[ni][nj] = k;
                    map[ni][nj] = map[i][j];
                    q.push({ni, nj});
                } else if(map[i][j] == 'M' && map[ni][nj] != 'M') {
                    map[ni][nj] = map[i][j];
                    q.push({ni, nj});
                }
            } else if(!is_valid(ni, nj) && map[i][j] == 'A') {
                fi = i;
                fj = j;
                finished = true;
            }
        }

    }

    if(fi == -1 && fj == -1) {
        return false;
    }

    while(fi != si || fj != sj) {
        int p_index = prev[fi][fj];
        path += dir[p_index];
        fi -= di[p_index];
        fj -= dj[p_index];
    }

    reverse(all(path));

    return true;

}

void solve() {

    int n, m;
    cin >> n >> m;

    vector<string> map(n);
    for(string &line : map) {
        cin >> line;
    }

    string path = "";

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(map[i][j] == 'A') {
                if(bfs(i, j, map, path)) {
                    cout << "YES\n" << path.size()  << '\n' << path << '\n';
                } else {
                    cout << "NO\n";
                }
                return;
            }
        }
    }

}

int main() {
	//cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    //cin >> T;

    while(T--) {
        solve();
    }

    return 0;
}