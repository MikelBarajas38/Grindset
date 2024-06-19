#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n;
    string prev, curr;

    cin >> n >> prev >> curr;

    int total = 0;
    for(int i = 0; i < n; ++i) {
        char big = max(prev[i], curr[i]);
        char small = min(prev[i], curr[i]);
        int diff = big - small;
        total += min(diff, 26 - diff);
    }

    cout << total << "\n";

    return 0;
}