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

    int W, H, X, Y;
    cin >> W >> H >> X >> Y; 

    if(W == 1 && (H - Y) % 2 == 0 && (Y - 1) % 2 == 0) {
        cout << "Lose\n";
    } else if (H == 1 && (W - X) % 2 == 0 && (X - 1) % 2 == 0) {
        cout << "Lose\n";
    } else if (H == 3 && W == 3 && X == 2 && Y == 2) {
        cout << "Lose\n";
    } else {
        cout << "Win\n";
    }

    return 0;
}
