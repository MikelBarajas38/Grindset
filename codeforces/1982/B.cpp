#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


void solve()
{

    int x, y, k;
    cin >> x >> y >> k;

    while(k > 0){

        if(x < y) {

            if(x + k < y) {
                x += k;
                break;
            }

            int rem = (x + k) % (y - 1);
            x = (rem) ? rem : y - 1;

            break;
        }
        
        int next_multiple = y - x % y;

        if(next_multiple >= k){
            x += k;
            while(x % y == 0) {
                x /= y;
            }
            break;
        } else {
            x += next_multiple;
            k -= next_multiple;
        }

        while(x % y == 0) {
            x /= y;
        }

    }

    cout << x << '\n';

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int T;
    cin >> T;

    while(T--){
        solve();
    }

    return 0;
}