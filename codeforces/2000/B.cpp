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

    vector<int> seats(n);
    for(int &s : seats) {
        cin >> s;
    }

    unordered_set<int> used;

    used.insert(seats[0]);

    for(int i = 1; i < n; i++) {

        int s = seats[i];

        if(used.count(s + 1) || used.count(s - 1)) {
            used.insert(s);
        } else {
            cout << "NO\n";
            return;
        }
        
    }

    cout << "YES\n";

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