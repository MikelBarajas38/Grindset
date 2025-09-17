#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {

    int n;
    cin >> n;

    vector<int> p(n);
    int max_i = 0;
    for(int i = 0; i < n; ++i) {
        cin >> p[i];
        if(p[i] == n) {
            max_i = i;
        }
    }

    int l = max_i - 1, r = max_i + 1, k = n - 1;
    while(k > 0) {

        if(l >= 0 && p[l] == k) {
            k--;
            l--;
        }else if(r < n && p[r] == k) {
            k--;
            r++;
        } else {
            break;
        }
    }

    if(k == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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