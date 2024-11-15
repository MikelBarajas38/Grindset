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

    string line = "";
    line.append(n-1, '.');
    line.append(1, '*');
    line.append(n-1, '.');

    int lim = 2 * n - 1;

    for(int i = 1; i < n; ++i) {

        cout << line << '\n';

        string next_line(lim, '.');

        for(int j = 0; j < lim; ++j) {
            
            bool left = j - 1 >= 0 && line[j - 1] == '*';
            bool right = j + 1 < lim && line[j + 1] == '*';

            if((left && !right) || (!left && right)) {
                next_line[j] = '*';
            }
        }

        line = next_line;

    }
    
    cout << line << '\n';


}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int T = 1;
    //cin >> T;

    while(T--) {
        solve();
    }

    return 0;
}