#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct teacher {
    ll c1;
    ll c2;
    ll c3;
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    ll L, T;
    cin >> L >> T;

    map<ll, teacher> teachers;
    for(ll i = 1ll; i <= T; i++) {
        teacher temp;
        cin >> temp.c1 >> temp.c2 >> temp.c3;
        teachers[i] = temp;
    }
    
    ll mx = 10e7;
    vector<vector<ll>> ks(T + 1ll, vector<ll>(L + 1ll, 0));
    ks[0][0] = 0ll;
    for(int i = 1; i <= L; ++i) {
        ks[0][i] = mx;
    }

    for(ll i = 1ll; i<=T; ++i) {
        for(ll w = 1ll; w <= L; w++) {

            ll mc = min(ks[i-1ll][w], teachers[i].c1 + ks[i-1ll][w - 1ll]);

            if(w >= 2ll) {
                mc = min(mc, teachers[i].c2 + ks[i-1ll][w - 2ll]);
            }

            if(w >= 3ll) {
                 mc = min(mc, teachers[i].c3 + ks[i-1ll][w - 3ll]);
            }

            ks[i][w] = mc;
        }
    }

    cout << ks[T][L] << '\n';


    return 0;
}