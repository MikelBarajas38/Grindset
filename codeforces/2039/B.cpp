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

    for(int i = 2; i <= n; ++i) {
        string sub = s.substr(i - 2, 2);
        if(sub[0] == sub[1]) {
            cout << sub << '\n';
            return;
        }
    }

    for(int i = 3; i <= n; ++i) {
        string sub = s.substr(i - 3, 3);
        if(sub[0] != sub[1] && sub[0] != sub[2] && sub[1] != sub[2]) {
            cout << sub << '\n';
            return;
        }
    }

    cout << "-1\n";

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