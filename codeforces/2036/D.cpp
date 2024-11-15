#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool valid(int i, int j, int m, int n) {
    return (i >= 0 && i < m && j >= 0 && j < n);
}

void solve() {
    
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for(string &s : grid) {
        cin >> s;
    }

    int i = 0, j = 0, offset = 0;
    vector<int> di = {0, 1, 0, -1};
    vector<int> dj = {1, 0, -1, 0};

    vector<vector<bool>> used(n, vector<bool>(m, false));
    vector<vector<bool>> used2(n, vector<bool>(m, false));
    int visited = 0;
    int lim = m * n;

    int ans = 0;
    
    while(visited < lim) {

        if(valid(i, j, n, m) && !used[i][j]) {
        
            int visited_2 = 0;
            int i2 = i, j2 = j, offset2 = offset;
            string num = "";

            while(visited_2 < 4) {

                if(valid(i2, j2, n, m) && !used2[i2][j2]) {
                    num += grid[i2][j2];
                    visited_2++;
                } else {
                    i2 -= di[offset2];
                    j2 -= dj[offset2];
                    offset2 = (offset2 + 1) % 4;
                }

                i2 += di[offset2];
                j2 += dj[offset2];

            }

            if (num == "1543") {
                ans++;
            }

            used[i][j] = true;
            visited++;

        } else { 

            i -= di[offset];
            j -= dj[offset];
            offset = (offset + 1) % 4;

            if(offset == 0) {
                used2 = used;
            }

        }

        i += di[offset];
        j += dj[offset];

    }

    cout << ans << '\n';

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int T;
    cin >> T;

    while(T--) {
        solve();
    }

    return 0;
}