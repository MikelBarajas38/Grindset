#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

map<char, ll> roman = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
};

void solve() {
    
    string s = "";
    cin >> s;

    int n = s.size();
    
    ll total = 0;
    for(char &c : s) {
        total += roman[c];
    }

    for(int i = n - 2; i >= 0; i--) {

        if (roman[s[i]] < roman[s[i + 1]]) {

            ll smaller = 0;
            int  j = i;
            while(j >= 0 && roman[s[j]] < roman[s[i + 1]]) {
                smaller += roman[s[j]];
                j--;
            }

            total -= 2 * smaller;
            i = j + 1;

        }
    }

    cout << total << '\n';

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