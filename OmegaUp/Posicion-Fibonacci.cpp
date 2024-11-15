#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {

	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    ull N;
    cin >> N;

    ull f_1 = 1, f_2 = 0, f;
    int i = 1;

    while(f_1 < N) {
        f = f_1 + f_2;
        f_2 = f_1;
        f_1 = f;
        i++;
    }

    if(f_1 == N) {
        cout << i << '\n';
    } else {
        cout << -1 << '\n';
    }

    return 0;

}