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

    vector<ll> points(n);
    for(ll &p : points) {
        cin >> p;
    }

    string rules;
    cin >> rules;

    vector<ll> prefix_sum(n + 1);
    for(int i = 1; i <= n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + points[i - 1];
    }

    ll score = 0;
    int p1 = 0, p2 = n - 1;

    while(p1 <= p2) {

        while(p1 < n && rules[p1] != 'L') {
            p1++;
        }

        while(p2 >= 0 && rules[p2] != 'R') {
            p2--;
        }

        if(p1 < p2) {
            score += prefix_sum[p2 + 1] - prefix_sum[p1];
        }

        p1++;
        p2--;

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