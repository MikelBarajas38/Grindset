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

    int n;
    cin >> n;
    vi v(n);

    vi c(32, 0);

    for (int &i : v) {
        cin >> i;

        for (int j = 0; j < 32; j++) {
            if (i & 1<<j){
                c[j]++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        int n = 0;
        for (int j = 0; j < 32; j++) {
            if (c[j]){
                n |= 1<<j;
                c[j]--;
            }
        }

        cout << n << ' ';
    }
    cout << '\n';    

    return 0;
}
