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

    vector<int> b(n);
    for(int &x : b) {
        cin >> x;
    }

    map<int, int> match;
    int match_count = 0;
    for(int &x : b) {
        if(match.count(k - x) && match[k - x] > 0) {
            match_count++;
            match[k - x]--;
        } else {
            match[x]++;
        }
    }

    int alice_moves = n - (match_count * 2);
    int ans = match_count - (alice_moves % 2);

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