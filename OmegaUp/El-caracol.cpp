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

    int p, s, r;
    cin >> p >> s >> r;

    int d = p / (s - r) - (p % (s - r) == 0);
    if(d < s) d = 1;
    
    cout << d << '\n';

    return 0;
}