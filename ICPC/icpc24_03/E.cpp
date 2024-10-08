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

    ll N;
    cin >> N;

    vector<vector<ll>> matrix(N, vector<ll>(N));

    for(ll i = 0; i < N; ++i) {
        for(ll j = 0; j < N; ++j) {
            cin >> matrix[i][j];
        }
    }

    bool r = matrix[0][0] < matrix[0][1];
    bool c = matrix[0][0] < matrix[1][0];

    if (r && c)
        cout << "0\n";
    else if (c)
        cout <<"1\n";
    else if (r)
        cout << "3\n";
    else
        cout << "2\n";

    return 0;
}
