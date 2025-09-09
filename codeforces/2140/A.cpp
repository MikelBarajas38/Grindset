#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

/*

    A B C
    C A B

    1010101
    0011101

    110100
    010110

    0110
    0110

    0011

    101
    110
    011

*/

void solve() {

    int n;
    cin >> n;

    string s;
    cin >> s;

    int zeros = 0;
    for(char &c : s) {
        if(c == '0') {
            zeros++;
        }
    }

    int sorted = 0;
    for(int i = 0; i < zeros; ++i) {
        if(s[i] == '0') {
            sorted++;
        }
    }

    cout << zeros - sorted << '\n';

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