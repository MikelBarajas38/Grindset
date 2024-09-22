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

    ll range = k;
    bool start_parity = (n - k + 1) % 2 == 0;
    bool end_parity = n % 2 == 0;

    ll even = range / 2;
    ll odd = even;

    if(range % 2 == 1) {
        if(start_parity) {
            even++;
        } else {
            odd++;
        }
    }

    odd = odd % 2;

    if(!odd) {
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