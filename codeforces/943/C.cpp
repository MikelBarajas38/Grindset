#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    
    int n;
    cin >> n;

    vector<ll> mods(n - 1);

    for(ll &i : mods) {
        cin >> i;
    }

    vector<ll> nums(n, 0);
    ll start = *max_element(all(mods));

    nums[0] = start + mods[0] + 1;
    for(ll i = 1; i < n; ++i) {
        nums[i] = nums[i - 1] + mods[i - 1];
    }

    for(ll &n : nums) {
        cout << n << ' ';
    }

    cout << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    vector<pair<int,int>> moves;
    int T;
    cin >> T;

    while(T--) {
        solve();
    }

    return 0;
}