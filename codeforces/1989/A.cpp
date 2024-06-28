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

    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;

        if(y < -1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int T = 1;
    //cin >> T;

    while(T--) {
        solve();
    }

    return 0;
}