#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll count_last_set_bits(ll x) {

    ll mask = 1, bit_count = 0;

    while(mask <= x && mask & x) {
        bit_count++;
        mask <<= 1;
    }

    return bit_count;

}

void solve() {

    ll n, x;
    cin >> n >> x;

    ll MEX = pow(2, count_last_set_bits(x));

    vector<ll> key;
    ll running_or = 0;

    for(ll i = 0; i <= MEX && i < n; ++i) {
        key.push_back(i);
        running_or |= i;
    }

    if(running_or != x) {
        key[key.size() - 1] = x;
    }

    while(key.size() < n) {
        key.push_back(x);
    }

    for(ll num : key) {
        cout << num << ' ';
    }
    cout << '\n';

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
