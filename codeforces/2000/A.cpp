#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {

    string n;
    cin >> n;

    if(n.size() <= 2) {
        cout << "NO\n";
        return;
    }

    string base = n.substr(0, 2);
    string last = n.substr(2);

    if(base != "10" || last[0] == '0' || last == "1") {
        cout << "NO\n";
    } else {
        cout << "YES\n";
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