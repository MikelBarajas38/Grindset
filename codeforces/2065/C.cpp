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

    vector<int> a(n);
    for(int &x : a) {
        cin >> x;
    }

    vector<int> b(m);
    for(int &x : b) {
        cin >> x;
    }

    int curr = min(a[0], b[0] - a[0]);

    for(int i = 1; i < n; i++) {

        int next_a = a[i];
        int next_b = b[0] - a[i];

        if(curr <= next_a && curr <= next_b) {
            curr = min(next_a, next_b);
        } else if(curr <= next_a) {
            curr = next_a;
        } else if(curr <= next_b) {
            curr = next_b;
        } else {
            cout << "NO\n";
            return;
        }

    }

    cout << "YES\n";

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