#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {

    string password;
    cin >> password;

    int n = password.size();

    char letter;

    for(int i = 1; i < n; i++) {
        if(password[i] == password[i-1]) {
            letter = (password[i] + 1 - 'a') % 26 + 'a';
            password = password.substr(0, i) + letter + password.substr(i);
            cout << password << '\n';
            return;
        }
    }

    letter = (password[n-1] + 1 - 'a') % 26 + 'a';
    password = password + letter;
    cout << password << '\n';

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