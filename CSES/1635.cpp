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

    int n, x;
    cin >> n >> x;

    vector<ll> coins(n);
    for(ll &c : coins){
        cin >> c;
    }
    
    vector<ll> comb(x+1);
    sort(all(coins));

    for(int i=0; i <= x; ++i){
        for(ll &c : coins){
            if(i == c) comb[i]++;
            if(i-c < 0 || i-c < c) continue;
            comb[i] += comb[i-c];
            comb[i] %= MOD;
        }
    }    

    cout << comb[n] << '\n';
    return 0;
}