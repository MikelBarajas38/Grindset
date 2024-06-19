#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pair<int, int>>;

using ll = long long;

ll INF = 10e6;

int main() {
    ll n, c;

    cin >> n >> c;

    ll current;

    cin >> current;

    if (current == 0) {
        cout << "0\n";
        return 0;
    }

    vector<ll> dp(n);
    dp[0] = current;

    for (int i = 1; i < n; i++)
    {
        ll x;
        cin >> x;
        dp[i] = max(0LL, dp[i-1]-c);
        dp[i] += x;
    }

    ll best = INF;
    int r;
    for (int i = 0; i < n; i++)
    {
        ll curr = (dp[i]+1ll)/c + ((dp[i]+1ll)%c != 0);

        if (curr < best && i+curr < n ) {
            best = curr;
            r = i;
        }
    }
    
    if (best == INF) {
        cout << "impossible\n";
    } else {
        cout << r << '\n';
    }

    return 0;
}