#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    
    ll n, k;
    cin >> n >> k;

    ll right = k - 1;
    ll left = n - k;

    if((!right || !left) && n > 1) {
        cout << -1 << '\n';
        return;
    }

    if(right > left) {

        cout << 2 * left + 1 << '\n';
        
        for(int i = 1; i <= left; i++) {
            cout << i << ' ';
        }

        cout << k << ' ';

        for(int i = k + 1; i <= left + k; i++) {
            cout << i << ' ';
        }

    } else {

        cout << 2 * right + 1 << '\n';

        ll diff = left - right;

        for(int i = 1; i <= left - diff; i++) {
            cout << i << ' ';
        }

        cout << k << ' ';

        for(int i = k + 1; i <= right + k; i++) {
            cout << i << ' ';
        }
        
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