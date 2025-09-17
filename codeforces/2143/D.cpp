#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int,null_type,less_equal<int>,rb_tree_tag,
    tree_order_statistics_node_update> indexed_multiset;

#define MOD 1000000007

void solve() {

    int n;
    cin >> n;

    indexed_multiset s;

    vector<int> a(n);
    for(int &x : a) {
        cin >> x;
        s.insert(x);
    }

    int total_bad = 0;
    for(int i = 0; i < n; ++i) {
        int x = a[i];
        s.erase(s.find_by_order(s.order_of_key(x)));
        int less_than = s.order_of_key(x);
        if(!less_than) continue;
        int bad_subsequences = less_than * (less_than - 1) / 2;
        total_bad = (total_bad + bad_subsequences % MOD) % MOD;
    }

    int total_subsequences = pow(2, n);

    cout << total_subsequences - total_bad << '\n';

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