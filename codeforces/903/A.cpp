#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {

    ll num;
    cin >> num;

    ll x = 1, z = num - 1, y;
    set<ll> used;

    while(x < z) {

        if(x % 3 == 0) {
            x++;
            continue;
        }

        if(z % 3 == 0) {
            z--;
            continue;
        }


        y = num - (x + z);
        if(y > 0 && y != x && y != z && y % 3 != 0) {
            break;
        } 

        if(y <= x) {
            z--;
        } else {
            x++;
        }
    }

    if(x < z) {
        cout << "YES\n" << x << " " << y << " " << z << "\n";
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