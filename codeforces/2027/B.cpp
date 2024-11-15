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
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_multiset;

void solve() {
    
    int n;
    cin >> n;

    vector<ll> a(n);
    for(ll &x : a) {
        cin >> x;
    }

    /*
    vector<ll> dp(n + 1, -INF);
    dp[0] = INF;

    for(int i = 0; i < n; i++) {
        int j = upper_bound(all(dp), a[i], greater<ll>()) - dp.begin();
        if(dp[j-1] >= a[i] && a[i] > dp[j]) {
            dp[j] = dp[j-1] != INF ? max(dp[j-1], a[i]) : a[i];
        }
    }

    int longest_stalinable_sequence = 0;
    for(int i = n; i >= 0; i--) {
        if(dp[i] != -INF) {
            longest_stalinable_sequence = i;
            break;
        }
    }
    */

    indexed_multiset right;
    for(int i = 0; i < n; i++) {
        right.insert(a[i]);
    }

    int longest_stalinable_sequence = 0;
    for(int i = 0; i < n; i++) {
        ll x = a[i];
        int smaller_or_equal = right.order_of_key(x + 1);
        longest_stalinable_sequence = max(longest_stalinable_sequence, smaller_or_equal);
        right.erase(right.find_by_order(right.order_of_key(x)));
    }    

    cout << n - longest_stalinable_sequence << '\n';
    
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