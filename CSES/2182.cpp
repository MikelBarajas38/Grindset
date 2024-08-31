#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<int MOD, int RT> struct mint {
	static const int mod = MOD;
	static constexpr mint rt() { return RT; } // primitive root
 	int v; 
 	explicit operator int() const { return v; } 
	mint():v(0) {}
	mint(ll _v):v(int(_v%MOD)) { v += (v<0)*MOD; }
	mint& operator+=(mint o) { 
		if ((v += o.v) >= MOD) v -= MOD; 
		return *this; }
	mint& operator-=(mint o) { 
		if ((v -= o.v) < 0) v += MOD; 
		return *this; }
	mint& operator*=(mint o) { 
		v = int((ll)v*o.v%MOD); return *this; }
	friend mint pow(mint a, ll p) { assert(p >= 0);
		return p==0?1:pow(a*a,p/2)*(p&1?a:1); }
	friend mint inv(mint a) { assert(a.v != 0); return pow(a,MOD-2); }
	friend mint operator+(mint a, mint b) { return a += b; }
	friend mint operator-(mint a, mint b) { return a -= b; }
	friend mint operator*(mint a, mint b) { return a *= b; }
};

using mi = mint<(int)1e9+7, 5>;

int main() {

    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n;
    cin >> n;

    vector<pair<int, int>> factors(n);
    for(int i = 0; i < n; i++) {
        cin >> factors[i].first >> factors[i].second;
    }

    mi num = 0;
    for(int i = 0; i < n; i++) {
        mi b = factors[i].first;
        ll p = factors[i].second;
        num += pow(b, p);
    }

    mi f_num = 0;
    for(int i = 0; i < n; i++) {
        mi p = factors[i].second;
        f_num *= (p + 1);
    }

    mi f_prod = 1;
    for(int i = 0; i < n/2; i++) {
        f_prod *=  num;
    }

    cout << int(f_num) << ' ' << int(f_sum) << ' ' << int(f_prod) << '\n';

    return 0;

}