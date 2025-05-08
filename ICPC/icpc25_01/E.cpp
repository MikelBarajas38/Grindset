#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define readv(_v) for (auto &_i : _v) cin >> i


int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, m;
    cin >> n >> m;

    int ans = -1;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if(x >= m && ans == -1) {
            ans = i + 1;
        }
    }

    cout << ans << '\n';

    return 0;
}