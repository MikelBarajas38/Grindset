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

    vector<int> needed = {3, 1, 2, 1, 0, 1, 0, 0, 0, 0};
    bool finished = false;

    for(int i = 0; i < n; ++i) {

        int d;
        cin >> d;

        if(finished) {
            continue;
        }

        if(needed[d]) {
            needed[d]--;
        }

        finished = true;
        for(int &x : needed) {
            if(x) {
                finished = false;
                break;
            }
        }

        if(finished) {
            cout << i+1 << '\n';
        }

    }

    if(!finished) {
        cout << 0 << '\n';
    }

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