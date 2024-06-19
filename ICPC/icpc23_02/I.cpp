#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    float n, m, k;

    cin >> n >> m >> k;

    n /= k;

    if (n >= m) {
        cout << "Iron fist Ketil\n";
    } else {
        cout << "King Canute\n";
    }    

    return 0;
}