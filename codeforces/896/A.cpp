// https://codeforces.com/contest/1869/problem/A
// Make it zero

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

    int T;
    cin >> T;

    while(T--) {
        
        int n;
        cin >> n;

        int x;
        for(int i=0; i<n; ++i) cin >> x;

        if(n%2) {
            cout << 4 << '\n';
            cout << 1 << ' ' << n-1 << '\n';
            cout << 1 << ' ' << n-1 << '\n';
            cout << n-1 << ' ' << n << '\n';
            cout << n-1 << ' ' << n << '\n';
        } else {
            cout << 2 << '\n';
            cout << 1 << ' ' << n << '\n';
            cout << 1 << ' ' << n << '\n';
        }

    }

    return 0;
}