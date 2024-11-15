#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    
    int N;
    cin >> N;

    bool odd = N % 2;

    N -= odd;

    int rhythm_count = 0;
    while(N) {
        rhythm_count++;
        N -= 2;
    }

    cout << rhythm_count << '\n';
    for(int i = 0; i < rhythm_count - odd; i++) {
        cout << 2 << ' ';
    }

    if(odd) {
        cout << 3;
    }

    cout << '\n';

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