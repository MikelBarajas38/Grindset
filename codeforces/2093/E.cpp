#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

using vi = vector<int>;
using vll = vector<ll>;
using vpi = vector<pair<int, int>>;
using pi = pair<int, int>;
using mi = vector<vector<int>>;
using mll = vector<vector<ll>>;

const ll MOD = 1000000007;
const int INF = 1000000000;

#define all(v) v.begin(), v.end()
#define loop while(true)
#define readv(v) for (auto &i : v) cin >> i
#define printv(v) for (auto &i : v) cout << i << ' '

#define lsz(x) ~(x) & (x+1)
#define lso(x) (x) & -(x)

vector<vector<int>> dist;

bool is_valid(int i, int j, int n, int m) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

void bfs(auto &map) {

    int n = map.size();
    int m = map[0].size();

    int si = -1, sj = -1;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(map[i][j] == 'E') {
                si = i;
                sj = j;
            } else if(map[i][j] == '#') {
                map[i][j] = 'W';
            }
        }
    }

    vector<int> di = {0, 1, 0, -1};
    vector<int> dj = {-1, 0, 1, 0};
    dist = vector<vector<int>>(n , vector<int>(m, INT_MAX));

    queue<pair<int, int>> q;
    q.push({si, sj});
    dist[si][sj] = 0;

    while(!q.empty()) {

        auto &[i, j] = q.front();
        q.pop();

        for(int k = 0; k < 4; ++k) {

            int ni = i + di[k];
            int nj = j + dj[k];

            if(is_valid(ni, nj, n, m) && map[ni][nj] == '.') {
                map[ni][nj] = 'V';
                dist[ni][nj] = dist[i][j] + 1;
                q.push({ni, nj});
            }

        }

    }

}

void solve() {

    int n, m;
    cin >> n >> m;

    vector<string> map(n);
    for(int i = 0; i < n; ++i) {
        cin >> map[i];
    }

    bfs(map);

    int q;
    cin >> q;

    vector<int> di = {0, 1, 0, -1};
    vector<int> dj = {-1, 0, 1, 0};
    vector<char> dir = {'L', 'D', 'R', 'U'};

    while(q--) {

        int i, j;
        cin >> i >> j;
        i--; j--;

        if(map[i][j] == '.') map[i][j] = '?';

        if(map[i][j] == 'V') {

            int bd = n * m;

            for(int k = 0; k < 4; ++k) {

                int ni = i + di[k];
                int nj = j + dj[k];

                if(is_valid(ni, nj, n, m) && dist[ni][nj] < bd) {
                    map[i][j] = dir[k];
                    bd = dist[ni][nj];
                }

            }
        }

        cout << map[i][j] << '\n';

    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t = 1;
    //cin >> t;

    while (t--)
        solve();

    return 0;
}

