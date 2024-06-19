#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int max_sum_sieve(int n) {

    int max_sum = 0, best = -1;

    vector<char> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            int sum = i;
            for (int j = i * 2; j <= n; j += i) {
                is_prime[j] = false;
                sum += j;
            }

            if (sum > max_sum) {
                max_sum = sum;
                best = i;
            }
        }
    }

    return best;

}

void solve() {

    int n;
    cin >> n;

    cout << max_sum_sieve(n) << "\n";

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}