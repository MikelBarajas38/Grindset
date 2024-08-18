#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {

    int n, m, k;
    cin >> n >> m >> k;

    int w;
    cin >> w;

    vector<ll> heights(w);
    for(ll &h : heights) {
        cin >> h;
    }
    
    vector<ll> row_pattern(n, k);
    vector<ll> col_pattern(m, k);

    for(int i = 0; i < k; i++) {
        row_pattern[i] = i + 1;
        col_pattern[i] = i + 1;
        row_pattern[n - i - 1] = i + 1;
        col_pattern[m - i - 1] = i + 1;
    }

    map<ll, ll> freq;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            freq[row_pattern[i] * col_pattern[j]]++;
        }
    }

    sort(all(heights), greater<ll>());

    ll score = 0;

    int i = 0;

    for(auto &[x, f] : freq) {

        while(i < w && f > 0) {
            score += heights[i] * x;
            f--;
            i++;
        }

        if(i >= w) break;

    }

    cout << score << '\n';
    
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