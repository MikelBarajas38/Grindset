#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {

    int n, k;
    cin >> n >> k;

    int available = 0, given = 0;
    for(int i = 0; i < n; i++) {

        int x;
        cin >> x;
        
        if(x >= k) {
            available += x;
        } else if(x == 0 && available) {
            available--;
            given++;
        }

    }

    cout << given << '\n';

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