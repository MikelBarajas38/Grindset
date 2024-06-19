#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool same(vi &diff1, vi &diff2, int offset){
    for(int i = 0; i<diff1.size(); i++) {
        if(diff1[i] != diff2[offset+i]) {
            return false;
        }
    }
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n,m;
    cin >> m >> n;

    vi a(m);
    for(int &i : a) cin >> i;

    vi b(n);
    for(int &i : b) cin >> i;

    vi diff1;
    for(int i = 1; i<m; ++i){
        diff1.push_back(a[i]-a[i-1]);
    }
    
    vi diff2;
    for(int i = 1; i<n; ++i){
        diff2.push_back(b[i]-b[i-1]);
    }

    int cont = 0;
    for(int i = 0; i <= n - m; i++){
        if(same(diff1, diff2, i)){
            cont++;
        }
    }

    cout << cont << "\n";

    return 0;
}