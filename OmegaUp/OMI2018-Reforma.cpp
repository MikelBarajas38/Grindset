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

    int n;
    cin >> n;

    vector<ll> edificios(n);
    for(ll &e : edificios) {
        cin >> e;
    }

    int current_sequence = 0, longest_sequence = 0;
    for(int i = 1; i < n; ++i) {
        if(edificios[i] < edificios[i - 1]) {
            current_sequence++;
        } else {
            longest_sequence = max(longest_sequence, current_sequence);
            current_sequence = 0;
        }
    }

    longest_sequence = max(longest_sequence, current_sequence);

    cout << longest_sequence + 1 << '\n';

    return 0;
}