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

    int n;
    cin >> n;

    int profit = 0;
    for(int i = 0; i < n; i++) {
        int k, p;
        cin >> k >> p;
        profit += k * p;
    }

    cout << profit << '\n';

    return 0;
}