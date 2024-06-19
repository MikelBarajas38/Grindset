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

    int a, b, c;
    cin >> a >> b >> c;

    if((a == b + c) || (b == a + c) || (c == a + b)) {
        cout << "1\n";
    } else if((a == b * c) || (b == a * c) || (c == a * b)) {
        cout << "2\n";
    } else {
        cout << "3\n";
    }

    return 0;
}