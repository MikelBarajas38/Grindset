#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> arr(n + 1);

    arr[0] = y % 2 ? -1 : 1;
    for(int i = 1; i <= n; i++) {
        if(i >= y && i <= x) {
            arr[i] = 1;
        } else {
            arr[i] = -arr[i - 1];
        } 
    }

    for(int i = 1; i <= n; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';

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