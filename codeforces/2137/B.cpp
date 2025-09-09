#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {

    ll a, b;
    cin >> a >> b;

    ll max_sum = -1;
    for(ll x = 1; x < 3; ++x) {
        if(b % x == 0) {
            ll sum1 = a * x + b / x;
            if(sum1 % 2 == 0 && sum1 > max_sum) {
                max_sum = sum1;
            }
            ll sum2 = a * (b / x) + x;
            if(sum2 % 2 == 0 && sum2 > max_sum) {
                max_sum = sum2;
            }
        }
    }

    cout << max_sum << '\n';

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
