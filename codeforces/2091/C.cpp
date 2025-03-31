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

    if(n % 2 == 0) {
        cout << -1 << '\n';
        return;
    }

    for(int i = 1; i <= n ; i+=2) {
        cout << i << ' ';
    }

    for(int i = 2; i <= n ; i+=2) {
        cout << i << ' ';
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