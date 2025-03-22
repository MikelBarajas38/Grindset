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

    vector<int> ans;

    for(int i = 0; i < n; ++i) {

        string beat;
        cin >> beat;

        for(int i = 0; i < 4; ++i) {
            if(beat[i] == '#') {
                ans.push_back(i + 1);
            }
        }

    }

    reverse(all(ans));

    for(int &x : ans) {
        cout << x << ' ';
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