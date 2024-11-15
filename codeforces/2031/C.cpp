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
        int curr = 1;
        for(int i = 0; i < n; i += 2) {
            cout << curr << ' ' << curr << ' ';
            curr++;
        }
        cout << '\n';
        return;
    }

    if (n < 26) {
        cout << -1 << '\n';
        return;
    }

    int curr = 2;
    for(int i = 0; i < n; i++) {
        if(i == 0 || i == 9 || i == 25) {
            cout << 1 << ' ';
        } else {
            cout << curr << ' ' << curr << ' ';
            curr++;
            i++;
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