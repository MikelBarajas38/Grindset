#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    map<int, int> order;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
        sort(all(a[i]));
        order[a[i][0]] = i;
    }

    bool valid = true;
    int prev = -1;
    for(int j = 0; j < m; j++) {
        for(auto &[x, i] : order) {
            if(a[i][j] < prev) {
                valid = false;
                break;
            }
            prev = a[i][j];
        }
    }

    if(!valid) {
        cout << -1 << '\n';
        return;
    } 

    for(auto &[x, i] : order) {
        cout << i + 1 << ' ';
    }
    cout << '\n';

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