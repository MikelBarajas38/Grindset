#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    
    int xc, yc, k;
    cin >> xc >> yc >> k;

    vector<int> x, y;

    if(k % 2 == 1) {
        x.push_back(xc);
        y.push_back(yc);
        k--;
    }

    int offset = 1;
    for(int i = 0; i < k; i += 2) {
        
        x.push_back(xc + offset);
        x.push_back(xc - offset);

        y.push_back(yc + offset);
        y.push_back(yc - offset);

        offset++;

    } 

    for(int i = 0; i < x.size(); i++) {
        cout << x[i] << " " << y[i] << '\n';
    }


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