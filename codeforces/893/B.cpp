#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    int n, m, d;
    cin >> n >> m >> d;

    vector<int> sellers(m+2);
    sellers[0] = 1 - d;
    for(int i = 1; i <= m; ++i) {
        cin >> sellers[i];
    }
    sellers[m+1] = n + 1;

    int eaten_original = 0;
    for(int i = 1; i <= m + 1; ++i) {
        int eaten_segment = (sellers[i] - sellers[i-1]) / d + 1;
        eaten_original += eaten_segment;
    }
    eaten_original--;

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int T;
    cin >> T;
 
    while(T--){
        solve();
    }

    return 0;
}