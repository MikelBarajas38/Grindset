#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef int ll;
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
    for(int i = 0; i < n; ++i) {

        string original_price;
        cin >> original_price;

        string converted_price;
        for(char &c : original_price) {
            if(c == '.') continue;
            converted_price += c;
        }

        ll price = stoi(converted_price);

        prices.push_back(price);

    }

    sort(all(prices), greater<>());

    ll sum = accumulate(all(prices), 0);

    vector<ll> dp(sum+1, -1);
    dp[0] = 0;

    for(int i = 0; i < n; ++i) {
        for(ll j = sum; j >= 0; --j) {
            if(dp[j] != -1) {

                ll normal_sum = j + prices[i];
                if(dp[normal_sum] == -1) {
                    dp[normal_sum] = dp[j] + 1;
                }

                ll normal_sum_next = get_next_5(normal_sum);
                if(normal_sum_next <= sum && dp[normal_sum_next] == -1) {
                    dp[normal_sum_next] = dp[j] + 1;
                }

                ll reduced_sum = j + get_next_5(prices[i]);
                if(reduced_sum <= sum && dp[reduced_sum] == -1) {
                    dp[reduced_sum] = dp[j] + 1;
                }

                ll reduced_sum_next = get_next_5(reduced_sum);
                if(reduced_sum_next <= sum && dp[reduced_sum_next] == -1) {
                    dp[reduced_sum_next] = dp[j] + 1;
                }

            }
        }
    }

    /*
    for(ll j = 0; j < sum + 1; ++j) {
        if(dp[j] != -1) {
            cout << j << ' ' << dp[j] << '\n';
        }
    }
    */


    for(ll j = 0; j <= sum; ++j) {
        if(dp[j] == n) {
            cout << get_two_digit_num(j) << '\n';
            return;
        }
    }


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