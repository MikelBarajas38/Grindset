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

    int q;
    cin >> q;

    while(q--) {

        ll n;
        cin >> n;

        ll m = (((ll) sqrt(n)) / 2) * 2 + 2;
        ll l = (n - (m-2)*(m-2)) / (m-1);
        ll p = (n - (m-2)*(m-2)) % (m-1);

        ll x, y;

        if (l == 0) {
            x = - (m/2) + 1 + p;
            y = (m/2) - 1;
        } else if (l == 1) {
            x = (m/2) - 1;
            y = (m/2) - 2 - p;
        } else if (l == 2) {
            x = (m/2) - 2 - p;
            y = - (m/2);
        } else if (l == 3) {
            x = - (m/2);
            y = - (m/2) + 1 + p;
        }
    
        
        ll d = 4 * (x*x + y*y);

        cout << d << '\n';
    }
    
    return 0;
}
