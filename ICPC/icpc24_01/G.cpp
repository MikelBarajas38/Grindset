#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll mex(vector<char> &s){
    ll m = 1;
    while(s[m]) m++;
    return m;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n;
    cin >> n;

    vector<char> s(1000000001, false);
    
    for(int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        s[x] = true;
    }

    if(mex(s) % 2) {
        cout << "Alicius\n";
    } else {
        cout << "Bobius\n";
    }


    return 0;
}