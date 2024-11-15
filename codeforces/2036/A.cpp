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

    vector<int> notes(n);
    for(int &x : notes) {
        cin >> x;
    }

    for(int i = 1; i < n; i++) {
        int diff = abs(notes[i] - notes[i-1]);
        if(diff != 5 && diff != 7) {
            cout << "NO" << '\n';
            return;
        }
    }

    cout << "YES" << '\n';

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