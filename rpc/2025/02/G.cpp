#include <bits/stdc++.h>
using namespace std;
//hey

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll get_next_5(ll x) {
    return x + (x % 5 < 3 ? - x % 5 : 5 - x % 5);
}

string get_two_digit_num(ll x) {

    string ans = to_string(x);
    string p1, p2;

    if(ans.length() == 1) {
        p1 = "0";
        p2 = "0" + ans;
    } else if(ans.length() == 2) {
        p1 = "0";
        p2 = ans;
    } else {
        p1 = ans.substr(0, ans.length() - 2);
        p2 = ans.substr(ans.length() - 2);
    }

    return p1 + "." + p2;
}

void solve() {

    int n;
    cin >> n;

    vector<ll> prices;
    ll final_price = 0;
    vector<ll> mod(5);

    for(int i = 0; i < n; ++i) {

        string original_price;
        cin >> original_price;

        string converted_price;
        for(char &c : original_price) {
            if(c == '.') continue;
            converted_price += c;
        }

        ll price = stoll(converted_price);

        mod[price%5]++;

        final_price += price;
        prices.push_back(price);

    }

    final_price -= mod[1];
    final_price -= (mod[2] * 2);

    ll three_four_pairs = min(mod[3], mod[4]);
    mod[3] -= three_four_pairs;
    mod[4] -= three_four_pairs;

    final_price -= (three_four_pairs * 2);

    if(mod[3]) {
        final_price - (mod[3]);
    } else {
        final_price - (mod[4] / 3 * 2);
    }

    cout << get_two_digit_num(final_price) << '\n';

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
