#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool is_valid(vector<string> &grid, int i, int j) {
    return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == '#';
}
int find_radius(vector<string> &grid, int i, int j) {

    int r = 0;
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    bool valid = true;

    for (r = 0; valid; r++) {
        for (int k = 0; k < 4; k++) {
            int ni = i + r * dx[k];
            int nj = j + r * dy[k];
            if (!is_valid(grid, ni, nj)) {
                valid = false;
                break;
            }
        }
    }

    return r - 1;

}

void solve() {

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    int max_r = 0;
    int a, b;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '#') {
                int r = find_radius(grid, i, j);
                if (r > max_r) {
                    max_r = r;
                    a = i;
                    b = j;
                }
            }
        }
    }

    cout << a + 1 << " " << b + 1 << "\n";

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}