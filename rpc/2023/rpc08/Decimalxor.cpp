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

    string a,b;

    cin >> a >> b;

    int max_len = max(a.length(), b.length());

    int pad_a = max_len - a.length();
    a.insert(0, pad_a, '0');

    int pad_b = max_len - b.length();
    b.insert(0, pad_b, '0');

    string ans = "";
    for(int i=0; i<max_len; i++){
        int num_a = a[i] - 48;
        int num_b = b[i] - 48;

        if((num_a <= 2 && num_b <= 2) || (num_a >= 7 && num_b >= 7)) {
            ans += '0';
        } else {
            ans += '9';
        }
    }

    cout << ans << '\n';

    return 0;
}