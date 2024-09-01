// By Fran408 (!nullptr)

#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vc = vector<char>;

int main(){
    ll n;
    vll arr;

    cin >> n;
    arr.resize(n);

    ll tot = 0;
    for (ll &a: arr) {
        cin >> a;
        tot += a;
    }

    if (tot % 2) {
        cout << -1;
        return 0;
    }

    tot /= 2;

    vll dp(tot + 1, 0);
    vc possible(tot + 1, 0);
    possible[0] = true;

    for (ll i = 0; i < n; i++) {
        for (ll &a: arr) {
            cout << a << ":" << endl;
            for (ll i = tot - a; i >= 0; i--) {
                if (possible[i]) {
                    if (possible[i + a]) continue;
                    //cout << "/t" << i << " made " << a + i << '\n';
                    possible[i + a] = true;
                    dp[i + a] = i;
                }
            }
        }
    }

    if (possible[tot] == false) {
        cout << -1;
        return 0;
    }

    vll an;

    for (ll i = tot; i != 0;) {
        an.push_back(i - dp[i]);
        i = dp[i];
    }

    multiset<ll> bs;

    for (ll &a: arr) {
        bs.insert(a);
    }

    for (ll &a: an) {
        //cout << a << " ";
        bs.erase(a);
    }

    vll bn;

    for (const ll &b: bs) {
        bn.push_back(b);
    }

    sort(all(an));
    sort(all(bn));

    ll c = 0;

    ll ai = 0, bi = 0;

    while (ai < an.size() && bi < bn.size()) {
        if (c < 0) {
            c += an[ai];
            cout << an[ai++] << " ";
        } else {
            c -= bn[bi];
            cout << bn[bi++] << " ";
        }
    }

    while (ai < an.size()) {
        cout << an[ai++] << " ";
    }

    while (bi < bn.size()) {
        cout << bn[bi++] << " ";
    }
}