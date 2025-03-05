#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n, q;
    cin >> n >> q;

    vector<ll> arr(n);
    for(ll &x : arr) {
        cin >> x;
    }

    vector<ll> prefix_sum(n+1);
    for(int i = 1; i <= n; i++) {
        prefix_sum[i] = prefix_sum[i-1] + arr[i-1];
    }

    while(q--) {

        int l, r;
        cin >> l >> r;

        ll big_range = prefix_sum[r];
        ll small_range = prefix_sum[l-1];

        ll range_sum = big_range - small_range;
        cout << range_sum << '\n';

    }

    return 0;

}