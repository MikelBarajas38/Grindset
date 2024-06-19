#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {

    int n;
    string s;

    cin >> n >> s;

    //ltr
    vi sums(n+1);
    for(int i = 1; i < n + 1; ++i) {
        sums[i] = sums[i-1] + (s[i-1] - '0'); 
    }

    map<int, int> complements;
    ll ans = 0;

    for(int i = 0; i < n + 1; ++i) {
        int subarrays = complements.count(i - sums[i]);
        if(subarrays){
            ans += complements[i-sums[i]];
        }
        complements[sums[i]]++;
    }

    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int T; 
    cin >> T;

    while(T--) {
        solve();
    }

    return 0;

}