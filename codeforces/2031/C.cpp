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

    vector<int> perfect_squares;
    for(int i = 1; i * i <= n; i++) {
        perfect_squares.push_back(i * i);
    }
    reverse(all(perfect_squares));
    perfect_squares.pop_back();

    if(perfect_squares.empty()) {
        cout << "-1\n";
        return;
    }

    vector<int> ans(n, 0);
    int curr = 1, used = 0, j = 0;

    for(int i = 0; i < n; i++) {

        if(ans[i] != 0) {
            continue;
        }

        if(n - used >= perfect_squares[j]) {
            ans[i] = curr;
            ans[i + perfect_squares[j] - 1] = curr;
            curr++;
            used += 2;
        } else if(j < perfect_squares.size()) {
            j++;
            i--;
        } else {
            cout << "-1\n";
            return;
        }

    }

    for(int x : ans) {
        cout << x << ' ';
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