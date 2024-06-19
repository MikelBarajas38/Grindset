#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;

#define all(v) v.begin(), v.end()
#define readv(v) for (auto &i : v) cin >> i
#define printv(v) for (auto &i : v) cout << i

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, q;
    cin >> n >> q;

    vector<string> v(n);
    readv(v);

    sort(all(v));

    while (q--) {
        string a, b;
        cin >> a >> b;

        auto ait = lower_bound(all(v), a);
        auto bit = lower_bound(all(v), b);

        int dist = bit - ait;
        if (*bit == b) dist ++;
        cout << dist << '\n';
    }

    return 0;
}
