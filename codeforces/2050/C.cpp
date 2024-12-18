#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    
    string num;
    cin >> num;

    ll sum = 0, twos = 0, threes = 0;
    for(char &c : num) {
        sum += c - '0';
        if(c == '2') twos++;
        if(c == '3') threes++;
    }

    if(threes == num.size()) {
        cout << "YES" << '\n';
        return;
    }

    ll next_multiple = sum % 9 == 0 ? sum : sum + (9 - sum % 9);
    ll diff = next_multiple - sum;

    if(diff == 0) {
        cout << "YES" << '\n';
        return;
    }

    while(diff <= twos * 2 + threes * 6) {
        
        ll og_diff = diff;
        ll twos_needed = 0, threes_needed = 0;

        while((diff - 6) > 0 && threes_needed < threes) {
            diff -= 6;
            threes_needed++;
        }

        while((diff - 2) > 0 && twos_needed < twos) {
            diff -= 2;
            twos_needed++;
        }

        if(diff == 0 && twos_needed <= twos && threes_needed <= threes) {
            cout << "YES" << '\n';
            return;
        }

        diff = og_diff + 9;

    }

    cout << "NO" << '\n';

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