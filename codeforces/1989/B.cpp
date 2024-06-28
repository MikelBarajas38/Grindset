#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {

    string a, b;
    cin >> a >> b;

    int best_matches = 0;
    for(int i = 0; i < b.size(); i++) {
        int current_matches = 0;
        int local_i = i;
        for(int j = 0; j < a.size() && local_i < b.size(); j++) {
            while(j < a.size() && b[local_i] != a[j]) {
                j++;
            }
            if(local_i < b.size() && j < a.size() && b[local_i] == a[j]) {
                current_matches++;
                local_i++;
            }
        }
        best_matches = max(best_matches, current_matches);
    }

    cout << b.size() + (a.size() - best_matches) << "\n";

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