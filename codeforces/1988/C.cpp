#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {

    ll n;
    cin >> n;

    ll len = 1, test = 1, msb = 0;
    while(test <= n) {
        if(n & test && test != n) {
            len++;
            msb = test;
        }
        test <<= 1;
    }

    cout << len << '\n';
   
    ll mask = msb;
    while(mask > 0) {
        if(mask & n && mask != n) {
            cout << (n ^ mask) << ' '; 
        }
        mask >>= 1;
    }
    cout << n << '\n';

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int T;
    cin >> T;

    while(T--) {
        solve();
    }
    return 0;
}