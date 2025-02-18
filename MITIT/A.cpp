#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll log5(ll n) {
    ll time = 0;

    while(n % 5 == 0) {
        n /= 5;
        time++;
    }

    if(n == 1) {
        return time;
    }

    while(n) {  
        n /= 5;
        time++;
    }
    return time;
}

void solve() {

    ll n;
    cin >> n;

    ll time = log5(n);

    if(time < 2) {
        cout << "MIT time\n";
    } else {
        cout << "MIT^" << time << " time\n";
    }

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