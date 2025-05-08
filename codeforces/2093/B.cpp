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

    int n = num.size();

    int i = n-1, deleted = 0;
    while(i >= 0) {
        if(num[i] != '0') {
            i--;
            break;
        }
        deleted++;
        i--;
    }

    while(i >= 0) {
        if(num[i] != '0') {
            deleted++;
        }
        i--;
    }

    cout << deleted << '\n';

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