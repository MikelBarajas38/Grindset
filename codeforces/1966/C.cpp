#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll mex(set<ll> &s){
    ll m = 1;
    while(s.count(m)) ++m;
    return m;
}

void solve() {
    int n;
    cin >> n;

    set<ll> s;
    
    for(int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        s.insert(x);
    }

    ll m = mex(s);
    if((m >= s.size() && n % 2) || (m < s.size() && m % 2)) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
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