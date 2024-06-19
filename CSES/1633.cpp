#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define MOD 1000000007

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    ll n;
    cin >> n;
 
    vector<ll> comb = {0,1,2,4,8,16,32};
    
    for(ll i=7; i<=n; ++i){
        ll ans = 0;
        for(ll j=1; j<=6; ++j){
            ans += comb[i-j];
            ans %= MOD;
        }
        comb.push_back(ans);
    }

    cout << comb[n] << '\n';
    return 0;
}