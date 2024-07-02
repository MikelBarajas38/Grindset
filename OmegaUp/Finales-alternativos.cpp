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

    int p1 = 0, p2 = 0;
    for(int i = 0; i < 64; ++i) {
        int x;
        cin >> x;
        p1 += x == 1;
        p2 += x == 2;
    }

    if(p1 > p2) {
        cout << "GANE\n";
    } else if(p2 > p1) {
        cout << "PERDI\n";
    } else {
        cout << "EMPATE\n";
    }

    return 0;
}