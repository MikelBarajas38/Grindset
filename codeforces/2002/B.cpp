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

    vector<int> alice(n);
    for(int &x : alice) {
        cin >> x;
    }

    vector<int> bob(n);
    for(int &x : bob) {
        cin >> x;
    }

    vector<int> reversed_bob = bob;
    reverse(all(reversed_bob));

    if(alice == bob || alice == reversed_bob) {
        cout << "Bob\n";
        return;
    }

    cout << "Alice\n";

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