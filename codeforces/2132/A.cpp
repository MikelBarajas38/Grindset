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

    string a;
    cin >> a;

    int m;
    cin >> m;

    string b;
    cin >> b;

    string order;
    cin >> order;

    string dima = "", vlad = "";
    for(int i = 0; i < m; ++i) {
        if(order[i] == 'D') {
            dima += b[i];
        } else {
            vlad += b[i];
        }
    }

    reverse(all(vlad));

    cout << vlad << a << dima << '\n';

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