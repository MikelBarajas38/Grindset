#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    
    ll n;
    cin >> n;

    set<ll> missing;

    while(missing.size() < 3) {

        ll l = 1, r = n;

        while(l < r) {
            
            ll m = (l + r) / 2;
            
            cout << "xor " << l << " " << m << '\n';
            cout.flush();

            ll left;
            cin >> left;

            cout << "xor " << m + 1 << " " << r << '\n';
            cout.flush();

            ll right;
            cin >> right;

            for(const ll &miss : missing) {
                if(miss >= l && miss <= m) {
                    left ^= miss;
                }
                if(miss >= m + 1 && miss <= r) {
                    right ^= miss;
                }
            }

            if(left >= right) {
                r = m;
            } else {
                l = m + 1;
            }

        }

        missing.insert(l);

    }

    cout << "ans " << *missing.begin() << ' ' << *next(missing.begin()) << ' ' << *next(missing.begin(), 2) << '\n';
    cout.flush();

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