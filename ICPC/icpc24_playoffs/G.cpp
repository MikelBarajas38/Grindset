#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n;
    cin >> n;

    vi v(n);

    for (int &i : v) cin >> i;

    int i = 1;
    int x = gcd(max(v[i-1], v[i]), min(v[i-1], v[i]));;
    int y;
    for (int i = 2; i < n; i++)
    {
        y = gcd(max(v[i-1], v[i]), min(v[i-1], v[i]));

        if (x != y) {
            cout << "NO\n";
            return 0;
        }

        x = y;
    }
    
    cout << "YES\n";
    
    return 0;
}
