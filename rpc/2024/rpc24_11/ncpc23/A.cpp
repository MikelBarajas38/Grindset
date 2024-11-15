#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {

    ll N, K;
    cin >> N >> K;

    ll ones = 0;
    vector<ll> kits(1);
    ll i;
    for(i = 0; i < N;) {
        
        // cout << 0;
        kits[0]++;
        i++;

        ll j = 0;
        while(i < N && kits[j] == K) {

            // cout << 1;
            ones++;
            i++;

            kits[j] = 0;
            j++;

            if(j == kits.size()) {
                kits.push_back(0);
            }

            kits[j]++;

        }

        if(j == K) {
            break;
        }

    }

    if(N > i) {
        ones += (N - i);
    }

    cout << ones << '\n';

}

int main() {
	//cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);

    int T = 1;
    // cin >> T;

    while(T--) {
        solve();
    }

    return 0;
}