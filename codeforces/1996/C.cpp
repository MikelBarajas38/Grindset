#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {

    int n, q;
    cin >> n >> q;

    string a, b;
    cin >> a >> b;

    a = "*" + a;
    b = "*" + b;

    vector<vector<int>> a_set(n + 1);
    vector<vector<int>> b_set(n + 1);

    a_set[0] = vector<int>(26, 0);
    b_set[0] = vector<int>(26, 0);

    for(int i = 1; i <= n; ++i) {


        a_set[i] = a_set[i - 1];
        a_set[i][a[i] - 'a']++;

        b_set[i] = b_set[i - 1];
        b_set[i][b[i] - 'a']++;

    }

    for(int i = 0; i < q; ++i) {

        int l, r;
        cin >> l >> r;

        vector<int> a_diff = a_set[r];
        for(int j = 0; j < 26; ++j) {
            a_diff[j] -= a_set[l - 1][j];
        }

        vector<int> b_diff = b_set[r];
        for(int j = 0; j < 26; ++j) {
            b_diff[j] -= b_set[l - 1][j];
        }

        int diff = 0;
        for(int j = 0; j < 26; ++j) {
            diff += abs(a_diff[j] - b_diff[j]);
        }

        cout << diff / 2 << '\n';

    }

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