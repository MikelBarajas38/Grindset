#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if((x1 > y1 && x2 > y2) || (y1 > x1 && y2 > x2)){ 
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

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