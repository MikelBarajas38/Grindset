#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {

    ll k, B[3];
    cin >> B[0] >> B[1] >> B[2] >> k;
    sort(B, B + 3);

    ll max_pos = 0;
    for (ll a = 1; a <= B[0]; a++){
        ll area = k / a;
        for (ll b = 1; b <= B[1]; b++){
            ll c = area / b;
            if (c > B[2]) continue;
            if (a * b * c == k){
                ll a_pos = B[0] - a + 1;
                ll b_pos = B[1] - b + 1;
                ll c_pos = B[2] - c + 1;
                max_pos = max(max_pos, a_pos * b_pos * c_pos);
            }
        }
    }

    cout << max_pos << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}