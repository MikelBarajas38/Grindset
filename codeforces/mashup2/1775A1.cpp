#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    
    string s;
    cin >> s;

    int a, b, c;
    a = 0;
    b = 1;
    
    



    cout << s.substr(0, b) << ' '
         << s.substr(b + 1, c - 1) << ' '
         << s.substr(c) << '\n';
    
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int T;
    cin >> T;
    while(T--){
        solve();
    }

    return 0;
}