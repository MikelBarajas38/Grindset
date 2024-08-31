#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll count_sellable_bottles(vector<ll> &bottles, ll mid, ll k) {

    ll sellable_bottles = 0, cost = 0, pos = upper_bound(all(bottles), mid) - bottles.begin() - 1;

    for(int i = pos; i >= 0; i--) {

        cost += (mid - bottles[i]);

        if(cost > k) {
            break;
        }

        sellable_bottles++;

    }

    return sellable_bottles;
}

int main() {    

	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    ll n, k;
    cin >> n >> k;

    vector<ll> bottles(n);
    for (ll &x : bottles) {
        cin >> x;
    }

    sort(all(bottles));

    ll l = *min_element(all(bottles)), r = *max_element(all(bottles));
    ll best_bottle_count = 0, best_mid = l;

    while(l <= r) {

        ll mid = l + (r - l) / 2;
        ll sellable_bottles = count_sellable_bottles(bottles, mid, k);

        if(sellable_bottles > best_bottle_count) {
            best_bottle_count = sellable_bottles;
            best_mid = l;
            l = mid + 1;
        } else {
            r = mid - 1;
        }

    }

    cout << best_bottle_count << ' ' << best_mid << '\n';
        
    return 0;

}