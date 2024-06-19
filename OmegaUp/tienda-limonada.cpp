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

    ll D, T, P, C, L;

    cin >> D >> T >> P >> C >> L;

    ll total = D - T + P * C;
    if(total >= L) {
        cout << "LIBRO\n";
    }
    else {
        cout << "LIMONADA\n";
    }

    return 0;
}