#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    
    int N, M;
    cin >> N >> M;

    vector<ll> items(N);
    for(ll &item : items) {
        cin >> item;
    }

    sort(all(items), greater<ll>());

    vector<ll> assigned_items(M);
    int j = 0, offset = 1;
    for(int i = 0; i < N; i++) {
        assigned_items[j] += items[i];
        j += offset;
        if (j == M || j == -1) {
            offset *= -1;
            j += offset;
        }
    }

    cout << *max_element(all(assigned_items)) << '\n';

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