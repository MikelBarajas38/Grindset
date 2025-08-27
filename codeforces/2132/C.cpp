#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define MAX 1000000001ll

void solve() {

    ll n, k;
    cin >> n >> k;

    ll w = 1;
    vector<ll> deal_w;
    map<ll, ll> deal_p;
    ll i = 0;
    while(w <= n) {
        deal_w.push_back(w);
        deal_p[w] = (w * 3 + i * (w / 3));
        w *= 3;
        i++;
    }

    ll deal_count = 0, final_cost = 1000000001, offset = 1;

    while(deal_count < k) {
        deal_count = 0;
        ll cost = 0;
        ll ni = n;
        for(int i = deal_w.size() - offset; i >= 0; --i) {
            ll x = ni / deal_w[i];
            deal_count += x;
            cost += x * deal_p[deal_w[i]];
            ni %= deal_w[i];
        }
        offset++;
        final_cost = min(final_cost, cost);
    }
    cout << final_cost << '\n';

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