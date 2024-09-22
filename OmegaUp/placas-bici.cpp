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

    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    ll digit_range = b - a + 1;
    ll char_range = d - c + 1;

    if(digit_range < 3 || char_range < 2) {
        cout << 0 << '\n';
        return 0;
    }

    ll digit_perm = digit_range * (digit_range - 1) * (digit_range - 2);
    ll char_perm = char_range * (char_range - 1);

    cout << digit_perm * char_perm << '\n';

    return 0;
}