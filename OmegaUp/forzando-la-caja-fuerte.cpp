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

    int l, r;
    cin >> l >> r;

    int diff = r % 5 - l % 5;

    if(diff < 0) {
        diff += 5;
    }

    int start = 5 - diff;

    for(int i = 0; i < 5; i++) {
        cout << (start + i) % 5 + 1 << " ";
    }


    return 0;

}