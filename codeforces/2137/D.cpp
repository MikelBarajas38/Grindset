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

    vector<int> freq(n+1);
    vector<int> b(n);
    bool possible = true;

    for(int &x : b) {
        cin >> x;
        freq[x]++;
    }

    for(int i = 1; i <= n; ++i) {
        if(freq[i] != 0 && freq[i] % i != 0) {
            possible = false;
            break;
        }
    }

    if(!possible) {
        cout << "-1\n";
        return;
    }

    int curr = 0;
    map<int, pair<int, int>> current_num;

    for(int &x : b) {

        if(!current_num.count(x)) {
            curr++;
            current_num[x] = {curr, x};
        }

        if(current_num[x].second == 0) {
            curr++;
            current_num[x] = {curr, x};
        }

        cout << current_num[x].first << ' ';

        current_num[x].second--;

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
