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

    int ones = 0, zeros = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '0') {
            while(i < n && s[i] == '0') {
                i++;
            }
            zeros++;
            i--;
        } else {
            ones++;
        }
    }   

    if(zeros >= ones) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
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