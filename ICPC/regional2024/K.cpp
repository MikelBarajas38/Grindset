#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

/*

3 00001111

2 00101101

3 1111100

1 1101100


3 0011100

  001010
*/

void solve() {

    int k;
    cin >> k;

    string s;
    cin >> s;

    int n = s.size();

    if(k == 2) {

        string s1 = string(n, '0');
        string s2 = string(n, '0');
        int moves1 = 0, moves2 = 0;

        for(int i = 0; i < n; ++i) {
            if(i % 2 == 0) {
                s1[i] = '1';
            } else {
                s2[i] = '1';
            }
            moves1 += (s[i] != s1[i]);
            moves2 += (s[i] != s2[i]);
        }

        if(moves1 < moves2) {
            cout << moves1 << ' ' << s1 << '\n';
        } else {
            cout << moves2 << ' ' << s2 << '\n';
        }

        return;


    }

    int c = 1, moves = 0;
    for(int i = 1; i < n; ++i) {
        if(s[i] == s[i-1]) {
            c++;
            if(c >= k) {
                if(i < n-1 && s[i+1] != s[i]) {
                    s[i-1] = 1 - (s[i-1] - '0') + '0';
                    c = 1;
                } else {
                    s[i] = 1 - (s[i] - '0') + '0';
                    c = 0;
                }
                moves++;
            }
        } else {
            c = 1;
        }
    }

    cout << moves << ' ' << s << '\n';

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