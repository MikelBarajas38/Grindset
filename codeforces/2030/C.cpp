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

    for(int i = 1; i < n; i++) {
        if(s[i] == s[i - 1] && s[i] == '1') {
            cout << "YES" << '\n';
            return;
        }
    }

    if(s[0] == '1' || s[n - 1] == '1') {
        cout << "YES" << '\n';
        return;
    }

    cout << "NO" << '\n';
    
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