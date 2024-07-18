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

    string s, t;
    cin >> s >> t;

    int first_one_s = n, first_one_t = n;

    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            first_one_s = i;
            break;
        }
    }

    for(int i = 0; i < n; i++) {
        if(t[i] == '1') {
            first_one_t = i;
            break;
        }
    }

    if(first_one_s <= first_one_t) {
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