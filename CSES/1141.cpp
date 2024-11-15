#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef unsigned long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {

	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n;
    cin >> n;

    map<int, int> pos;
    int longest_unique_sequence = 0;
    int l = 0;
    for(int r = 0; r < n; r++) {
        
        int x;
        cin >> x;

        if(pos.count(x)) {
            longest_unique_sequence = max(longest_unique_sequence, r - l);
            l = max(l, pos[x] + 1);
        }

        pos[x] = r;

    }

    longest_unique_sequence = max(longest_unique_sequence, n - l);

    cout << longest_unique_sequence << "\n";

    return 0;
}