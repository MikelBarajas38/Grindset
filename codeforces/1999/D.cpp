#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {

    string s, t;
    cin >> s >> t; 

    int j = 0;
    string example = s;
    for(int i = 0; i < s.size(); ++i) {

        if(j == t.size()) {
            break;
        }

        if(s[i] == t[j] || s[i] == '?') {
            if(s[i] == '?') {
                example[i] = t[j];
            }
            j++;
        }

    }

    for(char &c : example) {
        if(c == '?') {
            c = 'b';
        }
    }

    if(j == t.size()) {
        cout << "YES\n" << example << '\n';
    } else {
        cout << "NO\n";
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