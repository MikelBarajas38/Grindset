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

    string s;
    cin >> s;

    string rs = s;
    reverse(all(rs));

    string ans = "";

    if(s <= rs) {
        ans += s;
        if (n%2) {
            ans += rs;
        }
    } else {
        ans += rs;
        if(n%2 == 0) {
            ans += s;
        }
    }

    cout << ans << '\n';

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