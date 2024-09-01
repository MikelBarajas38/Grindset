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

    ll N;
    cin >> N;

    ll num = 1, den = 1;

    while(N--) {

        num += den;
        swap(num, den);  

    }

    cout << num << "\n";

    return 0;
}
