#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    
    string s;
    cin >> s;

    int n = s.size();

    int repeated_index = 0;
    for(int i = n - 1; i > 0; i--) {
        if(s[i] == s[i - 1]) {
            repeated_index = i;
            break;
        }
    }

    if(repeated_index) {
        cout << 1 << '\n';
        return;
    }

    cout << n << '\n';

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