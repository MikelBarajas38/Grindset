#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define MAX 100000

int main() {

	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    vector<ll> strategy_1(MAX + 1, 0);
    vector<ll> strategy_2(MAX + 1, 0);

    for(ll i = 1; i <= MAX; ++i) {
        
        ll x = i, prod = 1, sum = 0;
        while(x > 0) {
            prod *= x % 10;
            sum += (x % 10) * (x % 10);
            x /= 10;
        }

        strategy_1[i] = strategy_1[i - 1];
        strategy_2[i] = strategy_2[i - 1];

        if(prod > sum) {
            strategy_1[i]++;
        } else if (prod < sum) {
            strategy_2[i]++;
        }

    }

    int n;
    cin >> n;

    while(n--) {
        ll a, b;
        cin >> a >> b;
        
        ll strat_1_val = strategy_1[b] - strategy_1[a - 1];
        ll strat_2_val = strategy_2[b] - strategy_2[a - 1];

        cout << strat_1_val << ' ' << strat_2_val << '\n';
    }

    return 0;
}