#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<ll> v;

bool is_valid_max_sum(ll max_sum, ll k) {
    
    ll subarrays = 1;
    ll current_sum = 0;

    for(ll &i : v) {
        if(current_sum + i > max_sum) {
            if(i > max_sum) return false;
            subarrays++;
            current_sum = i;
        } else {
            current_sum += i;
        }
    }

    return subarrays <= k && current_sum <= max_sum;

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    ll n, k;
    cin >> n >> k;

    ll max_sum = 0;
    v.resize(n);
    for(ll &i : v) {
        cin >> i;
        max_sum += i;
    }

    ll l = 0;
    ll r = max_sum;

    while(l < r) {

        ll m = l + (r-l)/2;

        if(is_valid_max_sum(m, k)) {
            r = m;
        } else {
            l = m + 1;
        }

    }

    cout << r << "\n";

    return 0;
}