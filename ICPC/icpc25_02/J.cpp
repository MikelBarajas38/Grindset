#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define MAX 1000001
#define MOD 998244353

ll euclid(ll a, ll b, ll &x, ll &y) {
    if(!b) return x = 1, y = 0, a;
    ll d = euclid(b, a%b, y, x);
    return y -= a/b * x, d;
}

struct Mod {

    ll x;

    Mod() : x(1) {}

    Mod(ll _x) : x(_x) {}

    Mod operator+(Mod b) {
        return Mod((x + b.x) % MOD);
    }

    Mod operator-(Mod b) {
        return Mod((x - b.x + MOD) % MOD);
    }

    Mod operator*(Mod b) {
        return Mod((x * b.x) % MOD);
    }

    Mod operator/(Mod b) {
        return *this * inv(b);
    }

    Mod inv(Mod a) {
        ll x, y, g = euclid(a.x, MOD, x, y);
        return Mod((x + MOD) % MOD);
    }

    Mod operator^(ll e) {
        if(!e) {
            return Mod(1);
        }
        Mod r = *this ^ (e/2);
        r = r * r;
        return e & 1 ? *this * r : r;
    }

};

vector<Mod> fact(MAX);

void init() {
    fact[0] = Mod(1);
    for(ll x = 1; x <= MAX; ++x) {
        fact[x] = fact[x-1] * Mod(x);
    }
}

void solve() {

    ll N, K;
    cin >> N >> K;

    Mod ans = fact[N+1] / (fact[K+1] * fact[N-K]);

    cout << ans.x << '\n';

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    init();

    int T;
    cin >> T;

    while(T--) {
        solve();
    }

    return 0;
}