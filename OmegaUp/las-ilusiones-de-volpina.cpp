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

    vector<ll> nums(n);
    ll fact = 1, zeros = 0;
    for(ll &x : nums) {
        cin >> x;
        if(x == 0) {
            ++zeros;
        } else {
            fact *= x;
        }
    }

    if(zeros > 1) {
        for(ll &x : nums) {
            cout << 0 << ' ';
        }
        return 0;
    } 

    if(zeros == 1) {
        for(ll &x : nums) {
            if(x == 0) {
                cout << fact << ' ';
            } else {
                cout << 0 << ' ';
            }
        }
        return 0;
    }

    for(ll &x : nums) {
        cout << fact / x << ' ';
    }

    return 0;
}