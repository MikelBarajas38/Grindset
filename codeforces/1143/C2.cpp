#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    vector<int> does_not_respect(n + 1);

    for(int i = 1; i <= n; ++i) {
        int p, r;
        cin >> p >> r;

        if(p != -1) {
            adj[p].push_back(i);
        }

        does_not_respect[i] = r;
    }

    vector<int> ans;

    for(int i = 1; i <= n; ++i) {
        if(does_not_respect[i] == 1) {

            bool will_get_deleted = true;

            for(int &hijo : adj[i]) {
                if(does_not_respect[hijo] == 0) {
                    will_get_deleted = false;
                    break;
                }
            }

            if(will_get_deleted) {
                ans.push_back(i);
            }
        }
    }

    if(ans.empty()) {
        cout << -1 << '\n';
    } else {
        for(int &u : ans) {
            cout << u << ' ';
        }
        cout << '\n';
    }

    return 0;
}