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

    string s;
    cin >> s;

    ll eyes = 0, mouths = 0;
    for(char &c : s) {
        if(c == '-') {
            eyes++;
        } else {
            mouths++;
        }
    }

    ll left_eyes = eyes / 2;
    ll right_eyes = eyes / 2 + eyes % 2;

    cout << left_eyes * mouths * right_eyes << '\n';

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
