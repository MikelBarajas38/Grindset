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

    
    vector<set<int>> sets;
    set<int> union_set;

    for(int i=0; i<n; ++i) {
        set<int> s;

        int k;
        cin >> k;

        for(int j=0; i<k; ++j) {
            int x;
            cin >> x;
            s.insert(x);
            union_set.insert(x);
        }
    }

    

    for(int i=0; i<n; ++i)
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