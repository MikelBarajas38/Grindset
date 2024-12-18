#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    
    int n, m;
    cin >> n >> m;

    vector<int> lens(n);
    for(int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        lens[i] = s.size();
    }

    int i = 0;
    while(i < n && (m - lens[i]) >= 0) {
        m -= lens[i];
        i++;
    }
    
    cout << i << '\n';

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