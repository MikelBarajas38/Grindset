#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define readv(_v) for (auto &_i : _v) cin >> i


int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll k;
    cin >> k;

    vector<ll> ingredients(k);
    for(ll &i : ingredients) {
        cin >> i;
    }

    ll n;
    cin >> n;

    vector<vector<ll>> orders(n, vector<ll>(k));
    vector<ll> total(k);
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < k; ++j) {
            cin >> orders[i][j];
            total[j] += orders[i][j];
        }
    }

    ll last_day = LLONG_MAX;
    for(ll j = 0; j < k; ++j) {
        if(total[j] == 0) continue;
        ll day = ingredients[j] / total[j];
        last_day = min(last_day, day); 
    }

    for(ll j = 0; j < k; ++j) {
        ingredients[j] -= total[j] * last_day;
    }

    ll last_order = n + 1;
    for(ll i = 0; i < n; ++i) {
        if(last_order != n + 1) break;
        for(ll j = 0; j < k; ++j) {
            if(ingredients[j] < orders[i][j]) {
                last_order = i + 1;
            }
            ingredients[j] -= orders[i][j];
        }
    }

    cout << last_day + 1 << ' ' << last_order << '\n';

    return 0;
}