#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int T, Q;
    cin >> T >> Q;

    string s;
    cin >> s;

    vector<int> felices_encuentros(T + 1, 0);
    for(int i = 2; i <= T; ++i) {
        felices_encuentros[i] = felices_encuentros[i-1] + (s[i-1] == s[i-2] ? 1 : 0);
    }

    for(int i = 0; i < Q; ++i) {
        int L, R;
        cin >> L >> R;

        int ans = felices_encuentros[R] - felices_encuentros[L-1];
        if(L >=2 && s[L - 1] == s[L - 2]) ans--;

        cout << ans << '\n';
    }

    return 0;
}