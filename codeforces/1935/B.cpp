#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {

    int n;
    cin >> n;

    vector<int> a(n);
    for(int &i : a) {
        cin >> i;
    }

    int MEX = 0;
    vector<int> MEX_l2r;
    for(int i = 0; i < n; ++i) {
       if(a[i] <= MEX) {
            MEX = a[i] + 1;
       }
       MEX_l2r.push_back(MEX);  
    }

    MEX = 0;
    vector<int> MEX_r2l;
    for(int i = n - 1; i >= 0; --i) {
       if(a[i] <= MEX) {
            MEX = a[i] + 1;
       }
       MEX_r2l.push_back(MEX);  
    }

    if(MEX_l2r[n-1] != MEX_r2l[n-1]) {
        cout << "-1\n";
        return;
    }

    cout << MEX_l2r[n-1];

    int l = 0;
    

    

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