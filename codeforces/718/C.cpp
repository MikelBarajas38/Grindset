#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define MOD 1000000007

struct matrix {
    ll m[2][2];
};

matrix matmul2(matrix &a, matrix &b) {
    matrix c;
    c.m[0][0] = ((a.m[0][0] % MOD * b.m[0][0] % MOD) % MOD + (a.m[0][1] % MOD * b.m[1][0] % MOD) % MOD) % MOD;
    c.m[0][1] = ((a.m[0][0] % MOD * b.m[0][1] % MOD) % MOD + (a.m[0][1] % MOD * b.m[1][1] % MOD) % MOD) % MOD;
    c.m[1][0] = ((a.m[1][0] % MOD * b.m[0][0] % MOD) % MOD + (a.m[1][1] % MOD * b.m[1][0] % MOD) % MOD) % MOD;
    c.m[1][1] = ((a.m[1][0] % MOD * b.m[0][1] % MOD) % MOD + (a.m[1][1] % MOD * b.m[1][1] % MOD) % MOD) % MOD;
    return c;
}

matrix matpow2(matrix m, ll n) {
    matrix p{{{1, 0}, {0, 1}}};
    while(n) {
        if(n&1) {
            p = matmul2(p, m);
        }
        m = matmul2(m, m);
        n >>= 1;
    }
    return p;
}

ll fibo(ll n) {
    matrix b{{{0, 1}, {1, 1}}};
    return matpow2(b, n).m[0][1];
}

void solve() {

    int n;
    cin >> n;

    vector<string> ingredients(n);

    for(string &i : ingredients) {
        cin >> i;
    }

    cout << ingredients[0] << '\n';

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int T = 1;
    //cin >> T;

    while(T--) {
        solve();
    }

    return 0;
}