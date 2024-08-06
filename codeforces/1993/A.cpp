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

    string answer_sheet;
    cin >> answer_sheet;

    vector<int> option_freq(4, 0);
    for(char &option : answer_sheet) {

        if(option == '?') {
            continue;
        }

        option_freq[option - 'A']++;
    }

    int max_score = 0;
    for(int i = 0; i < 4; i++) {
        option_freq[i] = min(n, option_freq[i]);
        max_score += option_freq[i];
    }

    cout << max_score << '\n';

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