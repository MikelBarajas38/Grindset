#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

/*

4 2
1 2 1 2

1: 2
2: 2

{1: 1, 2: 1}

1 2 1 2

1 -
1 2 -
* 2 1

*/

void solve() {

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    vector<int> f(n+1);
    for(int &x : a) {
        cin >> x;
        f[x]++;
    }

    vector<int> goalf(n+1);
    for(int i = 1; i <= n; ++i) {
        if(f[i]) {
            if(f[i] % k != 0) {
                cout << 0 << '\n';
                return;
            } else {
                goalf[i] = f[i] / k;
            }
        }
    }

    ll awesome_subarrays = 0;
    vector<int> currf(n+1);
    ll l = 0, r = 0, last_r = 0;
    while(r < n) {
        if(currf[a[r]] == goalf[a[r]]) {
            ll size = r - l;
            ll overlap = last_r - l;
            awesome_subarrays += size * (size + 1) / 2;
            awesome_subarrays -= overlap * (overlap + 1) / 2;
            while(l <= r && currf[a[r]] == goalf[a[r]]) {
                currf[a[l]]--;
                l++;
            }
            last_r = r;
        } else {
            currf[a[r]]++;
            r++;
        }
    }

    bool last_valid = true;
    for(int i = 1; i <=n; ++i) {
        if(currf[i] > goalf[i]) {
            last_valid = false;
            break;
        }
    }

    if(last_valid) {
        ll size = r - l;
        ll overlap = last_r - l;
        awesome_subarrays += size * (size + 1) / 2;
        awesome_subarrays -= overlap * (overlap + 1) / 2;
    }

    cout << awesome_subarrays << '\n';

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