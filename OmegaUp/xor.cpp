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

    int n = 1;

    while(n > 0) {
        cin >> n;

        if(n == 0) {
            break;
        }

        vector<ll> B(n);
        for(ll &x : B) {
            cin >> x;
        }

        ll curr, acum = B[0];
        for(int i = 1; i < n; i++) {
            curr ^= acum;
            cout << curr << ' ';
            acum ^= B[i];
        }
        cout << curr << '\n';
    }
    
    return 0;
}