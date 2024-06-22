#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int no_calls = 0;

ll binomial_coeff(ll n, ll k) {

    no_calls++;

    if(k == 0 || k == n) {
        return 1;
    }

    return binomial_coeff(n - 1, k) + binomial_coeff(n - 1, k - 1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    ll n, k;
    cin >> n >> k; 

    cout << binomial_coeff(n, k) << ' ' << no_calls << '\n';

    return 0;
}