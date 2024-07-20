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

    vector<int> arr(n);
    vector<int> count(n + 1, 0);
    for(int &x : arr) {
        cin >> x;
        count[x]++;
    }

    for(int i = 0; i < n; i++) {
        if(count[arr[i]] % 2) {
            cout << "YES\n";
            return;
        }
    }
    
    cout << "NO\n";


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