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
    vector<ll> limits(2 * n - 1, 0);
    limits[0] = n;
    
    ll curr = n - 1;
    for(ll i = 1; i < (2 * n - 1); i += 2) {
        limits[i] = curr;
        limits[i + 1] = curr;
        curr--;
    }
    
    vector<ll> orig = limits;
    ll j = 0, diag = 0;
    for(ll i = 0; i < k; ++i) {
        limits[j]--;
        if(limits[j] == 0) {
            j++;
            diag++;
        }
    }

    if(j < limits.size() && limits[j] != orig[j]) {
        diag++;
    }
    
    cout << diag << '\n';

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