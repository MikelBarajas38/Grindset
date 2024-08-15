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

    vector<vector<int>> matrix(n + 1, vector<int>(m + 1));

    for(int i = 0; i <= n - k; i++) {
        for(int j = 0; j <= m - k; j++) {
            matrix[i][j]++;
            matrix[i][j+k]--;
            matrix[i+k][j]--;
            matrix[i+k][j+k]++;
        }
    }
    
    map<ll, ll, greater<ll>> freq;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i > 0) matrix[i][j] += matrix[i-1][j];
            if(j > 0) matrix[i][j] += matrix[i][j-1];
            if(i > 0 && j > 0) matrix[i][j] -= matrix[i-1][j-1];
            freq[matrix[i][j]]++;
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