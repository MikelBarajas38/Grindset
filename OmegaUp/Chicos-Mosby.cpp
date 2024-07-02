#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll squares = 0;

ll gcd(ll a, ll b) {
    if(b == 0) {
        return a;
    }
    squares += a / b;
    return gcd(b, a % b);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    ll a, b;
    cin >> a >> b;

    gcd(a, b);

    cout << squares << '\n';

    return 0;
}