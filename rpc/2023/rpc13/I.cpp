#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;

#define all(v) v.begin(), v.end()
#define readv(v) for (auto &i : v) cin >> i
#define printv(v) for (auto &i : v) cout << i

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ull n;
    ull d;

    cin >> n >> d;
    
    ull m;
    if (n%10 < d) {
        m = (n/10)*10+d;
    } else {
        m = (n/10)*10+10+d;
    }

    cout << m << '\n';

    return 0;
}
