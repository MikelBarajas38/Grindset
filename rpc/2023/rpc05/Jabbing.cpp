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

    int n, e;
    cin >> n >> e;

    int total = 0;
    
    for(int i = 0; i < n; ++i){
        int r;
        cin >> r;
        double p = M_PI * r * 2;
        double holes = p / e;
        if (holes / M_PI == int(holes / M_PI) && e != 1) {
            holes--;
        }
        total += holes;
    }

    cout << total;

    return 0;
}